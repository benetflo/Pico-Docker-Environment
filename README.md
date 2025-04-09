# Pico-Environment
Isolated environment using Docker for development on Raspberry Pi Pico W

## Make share folder on host computer to store uf2 files
```bash
mkdir ~/PicoEnv-share
```

## Build image, create container & link hostfolder to container folder
```bash
docker build -t pico-dev-environment .
docker run -p 2222:22 -v ${HOME}/PicoEnv-share:/home/devuser/share --name Pico-Dev -it pico-dev-environment
```
## SSH into container (Default password is set to 'dev')
```bash
ssh devuser@localhost -p 2222
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
SSH Keygen (Press Enter 3 times to store key  without password in default dir /home/devuser/.ssh/id_rsa)
```bash
ssh-keygen -t rsa -b 4096 -C "your.email@example.com"
```
Copy Public SSH key and add it to your Github profile
```bash
cat ~/.ssh/id_rsa.pub
```
