#!/bin/bash

# uncomment following line to show every instruction being run
set -x

# uncomment following line to show every instruction being run more verbosely
# set -vx

help() {
    printf 'Usage: %s <NAME>\n' "$(basename "$0")"
    exit 1
}

case "$1" in
	"-h" | "--help" | "help")
        printf 'Generate a new project directory with relevant files.\n\n'
        help
        ;;
esac


# EXTENSION=$(gum choose "c" "cpp" "py" "sh")
NAME=$(gum input --placeholder "Name of this project")
DESCRIPTION=$(gum write --placeholder "Description of this project")
# OWNER=$(gum write --placeholder "Owner of this project")

# The %F option is an alias for %Y-%m-%d
DATE=$(date +%F) # yyyy-mm-dd
YEAR=$(date +%Y) # yyyy


PROJECT_DIRECTORY=$HOME/repos/neos/${NAME}
TEMPLATES=$HOME/repos/neos/templates
EXTRAS=$HOME/repos/neos/extras

# check if NAME is 0 (not passed)
if [ -z "$NAME" ]; then
    help
    exit 1
elif ! [ -d "$TEMPLATES" ]; then
    printf 'Unable to find template directory: %s\n' "$TEMPLATES"
    exit 2
elif [ -d "$PROJECT_DIRECTORY" ]; then
    printf 'Project directory already exists: %s\n' "$PROJECT_DIRECTORY"
    exit 3
fi

CURRENT_DIRECTORY="$PWD"
cd $TEMPLATES
printf 'Please select a template'
select t in *; do
    template="$t"
    break
done

cd $CURRENT_DIRECTORY
cp -R ${TEMPLATES}/$template $PROJECT_DIRECTORY
cd $PROJECT_DIRECTORY
for t in *; do
    new=$(sed "s,DEFAULT,$NAME,g" <<< "$t")
    if [ "$t" = "$new" ]; then
        sed "s,DEFAULT,$NAME,g" < $t > temp
        mv -f temp $t
    else
        sed "s,DEFAULT,$NAME,g" < $t > $new
        if [ -e "$new" ]; then
            rm -f $t
        fi
    fi
done

cd $PROJECT_DIRECTORY && sed -I '' "s/{{YEAR}}/$YEAR/g" $PROJECT_DIRECTORY/LICENSE
cd $PROJECT_DIRECTORY && sed -I '' "s/{{DESCRIPTION}}/$DESCRIPTION/g" $PROJECT_DIRECTORY/README.md

# for the large c projects, build a src and include directory
if [ "$template" = "program.c" ]; then
    mkdir src
    mkdir include
    mkdir tests
    mv $NAME.h include
    cp $NAME.c tests/test_example.c
    mv $NAME.c src
fi

# initialize git in the project if user confirms
gum confirm "Initialize  git?" && cd $PROJECT_DIRECTORY && git init
