FROM ubuntu:22.04

# Use noninteractive only during apt to avoid prompts
RUN DEBIAN_FRONTEND=noninteractive apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    ca-certificates curl git make autoconf gcc g++ flex bison help2man \
    perl perl-doc libfl2 libfl-dev ccache numactl libgoogle-perftools-dev \
    pkg-config python3 python-is-python3 gperf \
    lcov gcovr pip

RUN pip install gcovr

# Workspace under /opt
WORKDIR /opt

RUN git clone https://github.com/frankjinn/module-fuzz /opt/module-fuzz && \
    git clone https://github.com/frankjinn/verilator_LLM_Fuzzer /opt/verilator && \
    git clone https://github.com/steveicarus/iverilog /opt/iverilog


#Instrumentation flags
ENV CC=gcc
ENV CXX=g++
ENV CFLAGS=" -fprofile-arcs -ftest-coverage"
ENV CXXFLAGS=" -fprofile-arcs -ftest-coverage"
ENV LFLAGS="--coverage"
ENV VERILATOR_ROOT="/opt/verilator"

# Build instrumented Verilator with coverage support
WORKDIR /opt/verilator
RUN autoconf && \
    ./configure
RUN make -j `nproc`

ENV PATH="/opt/verilator/bin:${PATH}"

# Build iverilog (without coverage instrumentation to avoid conflicts)
WORKDIR /opt/iverilog
RUN unset CFLAGS CXXFLAGS LFLAGS && \
    sh autoconf.sh && \
    ./configure --prefix=/opt/iverilog
RUN unset CFLAGS CXXFLAGS LFLAGS && make -j `nproc`
RUN make install

# Add iverilog to PATH
ENV PATH="/opt/iverilog/bin:${PATH}"

# Reinstate coverage instrumentation flags for Verilator coverage generation
ENV CFLAGS=" -fprofile-arcs -ftest-coverage"
ENV CXXFLAGS=" -fprofile-arcs -ftest-coverage"
ENV LFLAGS="--coverage"

# Needed to run gcovr
WORKDIR /opt/verilator/src
RUN ./bisonpre -d -v -o verilog.c verilog.y
RUN cp verilog.c obj_opt/
RUN cp verilog.y obj_opt/
RUN rm -r obj_dbg

# Python pkgs (fixes ENOENT via python-is-python3)
RUN python -m pip install --no-cache-dir \
    jupyter notebook numpy networkx matplotlib \
    coverage pytest-cov

# Create coverage directory
RUN mkdir -p /opt/coverage

EXPOSE 8888
CMD ["jupyter", "notebook", "--ip=0.0.0.0", "--no-browser", "--allow-root", "--NotebookApp.token="]
