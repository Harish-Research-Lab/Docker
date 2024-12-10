# Base ubuntu image
FROM ubuntu:22.04

# Set the environment to root
ENV HOME="/home"

# Set work directory
WORKDIR ${HOME}

# Install necessary modules
RUN apt update && \
    apt install -y \
    git build-essential gfortran vim \
    gdb duf mpich \ 
    && apt clean

# Open up bash command for usage
CMD ["bash"]
