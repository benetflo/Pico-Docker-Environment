ARG version=20.04
FROM ubuntu:${version}

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
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
    nano \
    vim \
    openssh-server \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install pyserial

RUN useradd -m -s /bin/bash devuser && \
    echo 'devuser:dev' | chpasswd && \
    echo 'devuser ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

RUN mkdir /var/run/sshd

USER devuser
WORKDIR /home/devuser/ws

RUN git clone --recurse-submodules https://github.com/raspberrypi/pico-sdk.git && \
    git clone https://github.com/raspberrypi/pico-examples.git

RUN wget https://github.com/Kitware/CMake/releases/download/v3.23.0/cmake-3.23.0-linux-x86_64.tar.gz && \
    tar -zxvf cmake-3.23.0-linux-x86_64.tar.gz && \
    sudo mv cmake-3.23.0-linux-x86_64 /opt/cmake && \
    sudo ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake && \
    rm cmake-3.23.0-linux-x86_64.tar.gz

ENV PICO_SDK_PATH=/home/devuser/ws/pico-sdk

RUN ssh-keygen -A

USER root
RUN echo "pico-container" > /etc/hostname
RUN echo 'export PS1="\u@pico-container:\w\$ "' >> /home/devuser/.bashrc && \
    echo 'export PICO_SDK_PATH=/home/devuser/ws/pico-sdk' >> /home/devuser/.bashrc

RUN sed -i 's/PasswordAuthentication no/PasswordAuthentication yes/' /etc/ssh/sshd_config

EXPOSE 22

CMD ["/usr/sbin/sshd", "-D"]
