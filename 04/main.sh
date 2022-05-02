#!/bin/bash

if [[ $# != 0 ]] ; then
    echo "Incorrect input"
else
    source config.txt
    export background_name_color=$column1_background
    export font_name_color=$column1_font_color
    export background_value_color=$column2_background
    export font_value_color=$column2_font_color

    export default_bkgr_name_clr=2
    export default_font_name_clr=3
    export default_bkgr_val_clr=2
    export default_font_val_clr=3

    if [[ -z $background_name_color ]]; then
        background_name_color=$default_bkgr_name_clr
    fi
    if [[ -z $font_name_color ]]; then
        font_name_color=$default_font_name_clr
    fi
    if [[ -z $background_value_color ]]; then
        background_value_color=$default_bkgr_val_clr
    fi
    if [[ -z $font_value_color ]]; then
        font_value_color=$default_font_val_clr
    fi

    if [[ $background_name_color == $font_name_color ]] ; then
        echo "Background and font colors of the name are the same"
        exit 1
    fi
    if [[ $background_value_color == $font_value_color ]] ; then
        echo "Background and font colors of the value are the same"
        exit 1
    fi

    for var in $background_name_color $font_name_color $background_value_color $font_value_color
    do
        if [[ $var =~ [^1-6] ]] ; then
            echo "Incorrect argument "$var""
            exit 1
        fi
    done

    chmod +x system_info.sh
    ./system_info.sh
fi
