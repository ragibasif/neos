#!/bin/bash

# Define colors
RED='\033[0;91m'
GREEN='\033[0;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
RESET='\033[0m' # Reset Color

NEOS="(${MAGENTA}neos${RESET})"
ERROR="${NEOS} [${RED}ERROR${RESET}]"
SUCCESS="${NEOS} [${GREEN}SUCCESS${RESET}]"
WARNING="${NEOS} [${YELLOW}WARNING${RESET}]"
INFO="${NEOS} [${BLUE}INFO${RESET}]"
QUESTION="${NEOS} [${BLUE}QUESTION${RESET}]"

clear

# echo -e "${ERROR} Example error message."
# echo -e "${SUCCESS} Example success message."
# echo -e "${WARNING} Example warning message."
# echo -e "${INFO} Example general informational message."


# Check if Git is installed
if ! command -v git &> /dev/null; then
    echo -e "${ERROR} Git is not installed or not in PATH." >&2
    exit 1
fi

# Ask user if they want to use a local template
echo -en "${QUESTION} "
read -p "Do you want to create a src directory for your project? (yes/no) " response
case "$response" in
 [yY][eE][sS]|[yY])
   # Check if the src directory exists
   # if [ ! -d ./src]; then
   #  mkdir ./src
   # fi
   echo "if [ ! -d ./src]; then"
   echo "mkdir ./src"
   echo "fi"
   ;;
 *) echo -e "${INFO}Skipping src directory creation..."
   ;;
esac


#  Cloning Repository
echo -e "${INFO} Cloning Repository ..."
echo -e "${INFO} git clone https://github.com/ragibasif/neos.git > /dev/null 2>&1"
# git clone https://github.com/ragibasif/neos.git > /dev/null 2>&1

# Ask user for confirmation
read -p "Do you want to continue? (yes/no) " response
case "$response" in
 [yY][eE][sS]|[yY])
     echo -e "${INFO} OK"
     ;;
 *)
     echo -e "${INFO} Exiting..."
     exit 1
     ;;
esac
