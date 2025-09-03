FROM ubuntu:22.04

# Use noninteractive only during apt to avoid prompts
RUN DEBIAN_FRONTEND=noninteractive apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    ca-certificates curl git make autoconf gcc g++ flex bison help2man \
    perl perl-doc libfl2 libfl-dev ccache numactl libgoogle-perftools-dev \
    pkg-config python3 python3-pip python-is-python3 \
    lcov gcovr pip \
    && rm -rf /var/lib/apt/lists/*

# Workspace under /opt
WORKDIR /opt

# Shallow clones to save time/space
RUN git clone --depth 1 https://github.com/frankjinn/module-fuzz /opt/module-fuzz && \
    git clone --depth 1 https://github.com/verilator/verilator /opt/verilator


#Instrumentation flags
ENV CC=gcc
ENV CXX=g++
ENV CFLAGS=" -fprofile-arcs -ftest-coverage"
ENV CXXFLAGS=" -fprofile-arcs -ftest-coverage"
ENV LFLAGS="--coverage"

# Build instrumented Verilator with coverage support
WORKDIR /opt/verilator
ARG rebuildVerilator=unknown
RUN autoconf && \
    ./configure \
    && make -j"$(nproc)"

# Needed to run gcovr
ARG rebuildSetup=unknown
WORKDIR /opt/verilator/src
RUN ./bisonpre -d -v -o verilog.c verilog.y
RUN cp verilog.c obj_opt/
RUN cp verilog.y obj_opt/
RUN rm -r obj_dbg

# Expose local (uninstalled) Verilator
ENV VERILATOR_ROOT=/opt/verilator
ENV PATH="/opt/verilator/bin:${PATH}"

# Python pkgs (fixes ENOENT via python-is-python3)
RUN python -m pip install --no-cache-dir \
    jupyter notebook numpy networkx matplotlib \
    coverage pytest-cov

# Create coverage directory
RUN mkdir -p /opt/coverage

EXPOSE 8888
CMD ["jupyter", "notebook", "--ip=0.0.0.0", "--no-browser", "--allow-root", "--NotebookApp.token="]
