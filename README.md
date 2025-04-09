# Pico-Environment
Isolated environment using Docker for development on Raspberry Pi Pico W


## Build image and create container
```bash
docker build -t pico-dev-environment .
docker run --name Pico-Dev -it pico-dev-environment
```

## Git config
```bash
git config --global user.name "Your name"
git config --global user.email "your.email@example.com"
```
Verify Git config
```bash
git config --global --list 
```
SSH Keygen
```bash
ssh-keygen -t rsa -b 4096 -C "your.email@example.com"
```
