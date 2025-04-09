ARG version=20.04
FROM ubuntu:${version}

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    libusb-1.0-0-dev \
    libudev-dev \
    gcc-arm-none-eabi \
    openocd \
    python3 \
    python3-pip \
    sudo \
    make \
    unzip \
    curl \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install pyserial

RUN useradd -m -s /bin/bash devuser && \
    echo 'devuser ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

USER devuser
WORKDIR /home/devuser/ws

RUN git clone --recurse-submodules https://github.com/raspberrypi/pico-sdk.git && \
    git clone https://github.com/raspberrypi/pico-examples.git

ENV PICO_SDK_PATH=/home/devuser/ws/pico-sdk

USER root
RUN echo "pico-container" > /etc/hostname
RUN echo 'export PS1="\u@pico-container:\w\$ "' >> /home/devuser/.bashrc

USER devuser
CMD ["/bin/bash"]
