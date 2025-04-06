#!/bin/bash

# Define colors
#
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
HELP="${NEOS} [${BLUE}HELP${RESET}]"
QUESTION="${NEOS} [${BLUE}QUESTION${RESET}]"

clear

# print to stderr
help() {
    >&2 echo -e "${HELP} Create a new project: $0 <PROJECT_NAME>"
    return 0
}

project_name=$1
project_directory="./${project_name}"
template_directory=./templates

# check if project_name is 0 (not passed)
if [ -z "$project_name" ]; then
    help
    exit 1
elif ! [ -d "$template_directory" ]; then
    >&2 echo -e "${ERROR} Unable to find template directory: $template_directory"
    exit 2
elif [ -d "$pdir" ]; then
    >&2 echo -e "${ERROR} Project directory already exists: $project_directory"
    exit 3
fi

current_directory="$PWD"
cd $template_directory
echo -e "${NEOS} Please select a template"
select t in *; do
    template="$t"
    break
done

cd $current_directory
cp -R ${template_directory}/$template $project_directory
cd $project_directory
for t in *; do
    new=$(sed "s,DEFAULT,$project_name,g" <<< "$t")
    if [ "$t" = "$new" ]; then
        sed "s,DEFAULT,$project_name,g" < $t > temp
        mv -f temp $t
    else
        sed "s,DEFAULT,$project_name,g" < $t > $new
        if [ -e "$new" ]; then
            rm -f $t
        fi
    fi
done

# for the large c projects, build a src and include directory
# TODO: Add test directory
if [ "$template" = "program.c" ]; then
    mkdir src
    mkdir include
    mv $project_name.c src
    mv $project_name.h include
    echo -e "${SUCCESS} Created src and include directory."
fi
cd ..


# Ask user for confirmation
echo -en "${QUESTION} "
read -p "Do you want initialize git for $project_name? (yes/no) " response
case "$response" in
 [yY][eE][sS]|[yY])
    # Check if Git is installed
    if ! command -v git &> /dev/null; then
        echo -e "${ERROR} Git is not installed or not in PATH." >&2
        exit 1
    fi
    cd $project_name
    git init .
    echo -e "${SUCCESS} Git is initialized for $project_name." >&2
    cd ..
     ;;
 *)
     echo -e "${NEOS} Exiting..."
     exit 1
     ;;
esac



###################################################
# References
# [Dr. Jonas Birch: bashbs](https://youtu.be/mRHy0e58S0s?feature=shared)
