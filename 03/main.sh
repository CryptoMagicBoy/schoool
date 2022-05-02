#!/bin/bash

if [[ $# != 4 ]] ; then
    echo "Incorrect input"
else
    for var in $*
    do
        if [[ $var =~ [^1-6] ]] ; then
            echo "Incorrect argument "$var""
            exit 1
        fi
    done
    export background_name_color=$1
    export font_name_color=$2
    export background_value_color=$3
    export font_value_color=$4

    if [[ $background_name_color == $font_name_color ]] ; then
        echo "Background and font colors of the name are the same"
        exit 1
    fi

    if [[ $background_value_color == $font_value_color ]] ; then
        echo "Background and font colors of the value are the same"
        exit 1
    fi

    chmod +x system_info.sh
    ./system_info.sh
fi
