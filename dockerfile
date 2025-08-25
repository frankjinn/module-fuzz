FROM ubuntu:22.04

# Use noninteractive only during apt to avoid prompts
RUN DEBIAN_FRONTEND=noninteractive apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    ca-certificates curl git make autoconf gcc g++ flex bison help2man \
    perl perl-doc libfl2 libfl-dev ccache numactl libgoogle-perftools-dev \
    pkg-config python3 python3-pip python-is-python3 \
    && rm -rf /var/lib/apt/lists/*

# Workspace under /opt
WORKDIR /opt

# Shallow clones to save time/space
RUN git clone --depth 1 https://github.com/frankjinn/module-fuzz /opt/module-fuzz && \
    git clone --depth 1 https://github.com/verilator/verilator /opt/verilator

# Build Verilator IN-PLACE (no make install)
WORKDIR /opt/verilator
ARG rebuildVerilator=unknown
RUN autoconf && ./configure && make -j"$(nproc)"

# Expose local (uninstalled) Verilator
ENV VERILATOR_ROOT=/opt/verilator
ENV PATH="/opt/verilator/bin:${PATH}"

# Python pkgs (fixes ENOENT via python-is-python3)
RUN python -m pip install --no-cache-dir \
    jupyter notebook numpy networkx matplotlib

EXPOSE 8888
CMD ["jupyter", "notebook", "--ip=0.0.0.0", "--no-browser", "--allow-root", "--NotebookApp.token="]
