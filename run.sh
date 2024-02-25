#!/usr/bin/env bash

gcc -o socket socket.c

strace ./socket
