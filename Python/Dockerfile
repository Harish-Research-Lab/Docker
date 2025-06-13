# Base ubuntu image
FROM ubuntu:25.10

# Install system packages including venv support
RUN apt-get update && apt-get install -y \
    build-essential \
    python3-dev \
    python3-venv \
    python3-pip \
    ninja-build \
    meson \
    git \
    pkg-config \
    libfreetype6-dev \
    libpng-dev \
    libopenblas-dev \
    gfortran \
    libjpeg-dev \
    zlib1g-dev \
    libssl-dev \
    libffi-dev \
    cmake \
 && rm -rf /var/lib/apt/lists/*

# Create a venv named "project_env" under /opt
RUN python3 -m venv /opt/project_env

# Ensure the venv is activated on container start
ENV VIRTUAL_ENV=/opt/project_env
ENV PATH="$VIRTUAL_ENV/bin:$PATH"

# Upgrade pip inside the venv and install basic packages
RUN pip install --upgrade pip 
RUN pip install 'numpy>=2.2.5'
RUN pip install 'pandas>=2.2.3'
RUN pip install 'seaborn>=0.13.1'
RUN pip install 'matplotlib>=3.10.2'
RUN pip install 'scikit_learn>=1.6.0'

# Install PyTorch - let pip choose the latest available version
ARG TARGETARCH
RUN if [ "$TARGETARCH" = "amd64" ]; then \
        # AMD64: Install latest CUDA-enabled PyTorch
        pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu124; \
    elif [ "$TARGETARCH" = "arm64" ]; then \
        # ARM64: Install latest CPU-only version
        pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cpu; \
    else \
        echo "PyTorch not available for $TARGETARCH architecture"; \
    fi

# Default to bash with venv already activated
# WORKDIR /home
# CMD ["bash"]