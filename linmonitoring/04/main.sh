#!/bin/bash

if [[ $# != 0 ]] ; then
    echo "Incorrect input"
else
    source config
    
    default_back_name=6
    default_font_name=1
    default_back_value=2
    default_font_value=4
    
    if [[ -z $column1_background || -z $column1_font_color || -z $column2_background || -z $column2_font_color ]] ; then
        export back_name=$default_back_name
        export font_name=$default_font_name
        export back_value=$default_back_value
        export font_value=$default_font_value
        export check=1
    else
        export back_name=$column1_background
        export font_name=$column1_font_color
        export back_value=$column2_background
        export font_value=$column2_font_color
        export check=0
    fi
    
    if [[ $back_name = $font_name || $back_value = $font_value ]] ; then
        echo "Background color and font color are match! Try again."
        exit 1
    fi
    
    for p in $back_name $font_name $back_value $font_value
    do
        if [[ $p != 1 && $p != 2 && $p != 3 && $p != 4 && $p != 5 && $p != 6 ]] ; then
            echo Incorrect input parameters
            exit 1
        fi
    done
    
    chmod +x colors.sh
    ./colors.sh $back_name $font_name $back_value $font_value $check
fi

exit 0
