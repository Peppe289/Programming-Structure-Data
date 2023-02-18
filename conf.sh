#!/bin/bash

# VSCode local config directory
VSCode=".vscode"
VSFILE=("launch.json" "settings.json" "tasks.json")

# remote sync
REMOTE="https://raw.githubusercontent.com/Peppe289/Programming-C/main/.vscode"

remote_sync() {
    curl "$REMOTE/$1" -o "$VSCode/$1"
    if [ $? -ne 0 ]; then
        echo "Failled to clone. Please install 'curl'"
        exit 1
    fi
}

GDB=$(which gdb &> /dev/null)

if [[ -z $GDB ]]; then
    echo "Please install GDB before."
fi

if [[ -d $VSCode ]]; then
    echo "VSCode directory exist"
else
    mkdir $VSCode
fi

for file in ${VSFILE[@]}; do
    if [[ -f "$VSCode/$file" ]]; then
        echo "$VSCode/$file : Exist"
        read -p "Your want overwrite? [y/N] : " input
        if [ "$input" == "Y" ] || [ "$input" == "y" ]; then
            # curl "$REMOTE/$file" -o "$VSCode/$file"
            remote_sync $file
        fi
    else
        # curl "$REMOTE/$file" -o "$VSCode/$file"
        remote_sync $file
    fi
done
