# Pico-Environment
Isolated environment using Docker for development on Raspberry Pi Pico W


## Build image and create container
```bash
docker build -t pico-dev-environment .
docker run --name Pico-Dev -it pico-dev-environment
```
