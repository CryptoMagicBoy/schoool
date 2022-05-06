#!/bin/bash

if [[ $# != 4 ]] ; then
    echo "Incorrect input"
else
    for p in $*
    do
        if [[ $p != 1 && $p != 2 && $p != 3 && $p != 4 && $p != 5 && $p != 6 ]] ; then
            echo Incorrect input parameters
            exit 1
        fi
    done
    if [[ $1 = $2 || $3 = $4 ]] ; then
        echo "Background color and font color are match! Try again."
        exit 1
    fi 
    chmod +x colors.sh
    ./colors.sh "$1" "$2" "$3" "$4"
fi
