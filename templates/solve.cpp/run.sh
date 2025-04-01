#!/bin/bash

MAGENTA='\033[0;95m'
RESET='\033[0m'

echo -e "${MAGENTA}make clean && make all && ./solve${RESET}"
make clean && make all && ./solve
