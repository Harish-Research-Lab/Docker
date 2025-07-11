# Base ubuntu image
FROM ubuntu:22.04

# Set the environment to root
ENV HOME="/home"

# Set work directory
WORKDIR /opt 

# Install necessary modules
RUN apt update && \
    apt install -y \
    git build-essential gfortran vim \
    gdb duf \
    cmake wget openmpi-bin \ 
    libopenmpi-dev \
    libmpich-dev \
    && rm -rf /var/lib/apt/lists/*

    # Build coarrays
RUN git clone https://github.com/sourceryinstitute/OpenCoarrays.git && \
    cd OpenCoarrays && \
    mkdir build && cd build && \
    cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
    make -j$(nproc) && make install

ENV PATH="/usr/local/bin:$PATH"

# Open up bash command for usage
CMD ["/bin/bash"]