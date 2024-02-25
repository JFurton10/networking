FROM ubuntu:latest

WORKDIR /app

RUN apt update && apt upgrade -y && \
    apt install -y vim \
    build-essential \
    tree \
    ripgrep \
    fzf \
    netcat \
    strace

COPY . /app

COPY vimrc /root/.vimrc

