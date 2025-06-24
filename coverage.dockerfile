#Note to self, everything is automatically run under sudo
FROM ubuntu:22.04

RUN apt-get update
RUN apt-get -y install curl 

#Prereqs
RUN apt-get -y install \
                git help2man perl python3 make autoconf gcc g++ flex bison ccache \ 
                libgoogle-perftools-dev numactl perl-doc \
                libfl2 \
                libfl-dev \
                pip

#Building proscess
RUN git clone https://github.com/frankjinn/module-fuzz
RUN git clone https://github.com/verilator/verilator
WORKDIR /
WORKDIR /verilator

RUN unset VERILATOR_ROOT
RUN git pull

#After changing src of verilator, rebuild from here
ARG rebuildVerilator=unknown

RUN autoconf
RUN ./configure
RUN make -j `nproc`

#Instrumentation flags
ENV VER_ROOT="/verilator"

WORKDIR /
RUN pip install --no-cache-dir jupyter notebook numpy networkx matplotlib
EXPOSE 8888
CMD ["jupyter", "notebook", "--ip", "0.0.0.0", "--no-browser", "--allow-root", "--NotebookApp.token=''"]