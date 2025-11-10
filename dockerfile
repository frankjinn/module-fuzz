FROM ubuntu:22.04

# Use noninteractive only during apt to avoid prompts
RUN DEBIAN_FRONTEND=noninteractive apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    ca-certificates curl git make autoconf gcc g++ flex bison help2man \
    perl perl-doc libfl2 libfl-dev ccache numactl libgoogle-perftools-dev \
    pkg-config python3 python-is-python3 gperf \
    lcov gcovr pip \
    libreadline-dev zlib1g-dev tcl-dev libffi-dev graphviz xdot

RUN pip install gcovr

# Workspace under /opt
WORKDIR /opt

RUN git clone https://github.com/frankjinn/module-fuzz /opt/module-fuzz && \
    git clone https://github.com/frankjinn/verilator_LLM_Fuzzer /opt/verilator && \
    git clone https://github.com/steveicarus/iverilog /opt/iverilog && \
    git clone https://github.com/YosysHQ/yosys.git /opt/yosys

# Set basic compiler environment (no instrumentation yet)
ENV CC=gcc
ENV CXX=g++

# Build Icarus Verilog first (without coverage instrumentation)
WORKDIR /opt/iverilog
RUN sh autoconf.sh && \
    ./configure --prefix=/opt/iverilog
RUN make -j `nproc`
RUN make install

# Add iverilog to PATH
ENV PATH="/opt/iverilog/bin:${PATH}"

# Build Yosys for CXXRTL backend (third simulator)
# Yosys with CXXRTL provides a fast, open-source cycle-based simulator for arbitration
WORKDIR /opt/yosys
# Initialize git submodules (needed for ABC and other dependencies)
RUN git submodule update --init --recursive
# Build Yosys
RUN make config-gcc && \
    make -j `nproc`
RUN make install

# Add Yosys to PATH
ENV PATH="/opt/yosys:${PATH}"

# Install C++ compiler tools for CXXRTL simulation
RUN DEBIAN_FRONTEND=noninteractive apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    clang libclang-dev && \
    rm -rf /var/lib/apt/lists/*

# Now set coverage instrumentation flags for Verilator
ENV CFLAGS=" -fprofile-arcs -ftest-coverage"
ENV CXXFLAGS=" -fprofile-arcs -ftest-coverage"
ENV LFLAGS="--coverage"
ENV VERILATOR_ROOT="/opt/verilator"

# Build instrumented Verilator with coverage support (built LAST)
WORKDIR /opt/verilator
RUN autoconf && \
    ./configure
RUN make -j `nproc`

ENV PATH="/opt/verilator/bin:${PATH}"

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
