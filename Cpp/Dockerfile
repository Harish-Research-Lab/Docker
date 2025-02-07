# Use Ubuntu as a base image (works on both ARM and x86)
FROM ubuntu:22.04

# Set non-interactive mode for package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install system dependencies and build tools
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    libeigen3-dev \
    libopenmpi-dev \
    openmpi-bin \
    && rm -rf /var/lib/apt/lists/*

# Set working directory inside the container
WORKDIR /workspace

# Copy the entire project (source code, CMakeLists.txt)
COPY . /workspace

# Create build directory and compile the FEM solver with OpenMP & MPI support
RUN mkdir -p build && cd build && cmake -DUSE_OPENMP=ON -DUSE_MPI=ON .. && make -j$(nproc)

# Set default command to run the FEM solver with 4 MPI processes
CMD ["mpirun", "-np", "4", "./build/fem_solver"]