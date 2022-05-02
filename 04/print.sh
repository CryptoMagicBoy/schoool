#!/bin/bash

whiteF="\033[37m"
redF="\033[31m"
greenF="\033[32m"
blueF="\033[34m"
purpleF="\033[35m"
blackF="\033[30m"

whiteB="\033[47m"
redB="\033[41m"
greenB="\033[42m"
blueB="\033[44m"
purpleB="\033[45m"
blackB="\033[40m"

end="\e[0m"

case $background_name_color in
    1)bgr_name_clr=$whiteB;;
    2)bgr_name_clr=$redB;;
    3)bgr_name_clr=$greenB;;
    4)bgr_name_clr=$blueB;;
    5)bgr_name_clr=$purpleB;;
    6)bgr_name_clr=$blackB;;
esac

case $font_name_color in
    1)font_name_clr=$whiteF;;
    2)font_name_clr=$redF;;
    3)font_name_clr=$greenF;;
    4)font_name_clr=$blueF;;
    5)font_name_clr=$purpleF;;
    6)font_name_clr=$blackF;;
esac

case $background_value_color in
    1)bgr_value_color=$whiteB;;
    2)bgr_value_color=$redB;;
    3)bgr_value_color=$greenB;;
    4)bgr_value_color=$blueB;;
    5)bgr_value_color=$purpleB;;
    6)bgr_value_color=$blackB;;
esac

case $font_value_color in
    1)font_value_clr=$whiteF;;
    2)font_value_clr=$redF;;
    3)font_value_clr=$greenF;;
    4)font_value_clr=$blueF;;
    5)font_value_clr=$purpleF;;
    6)font_value_clr=$blackF;;
esac

echo -e "${bgr_name_clr}${font_name_clr}HOSTNAME${end} = ${bgr_value_color}${font_value_clr}$HOSTNAME${end}"

echo -e "${bgr_name_clr}${font_name_clr}TIMEZONE${end} = ${bgr_value_color}${font_value_clr}$TIMEZONE${end}"
echo -e "${bgr_name_clr}${font_name_clr}USER${end} = ${bgr_value_color}${font_value_clr}$USER${end}"
echo -e "${bgr_name_clr}${font_name_clr}OS${end} = ${bgr_value_color}${font_value_clr}$OS${end}"
echo

color[1]=" (white)"
color[2]=" (red)"
color[3]=" (green)"
color[4]=" (blue)"
color[5]=" (purple)"
color[6]=" (black)"

echo -n "Column 1 background = "
if [[ $background_name_color == $default_bkgr_name_clr ]]; then
    echo -n "default"
else
    echo -n "$background_name_color"
fi
echo "${color[$background_name_color]}"

echo -n "Column 1 font color = "
if [[ $font_name_color == $default_font_name_clr ]]; then
    echo -n "default"
else
    echo -n "$font_name_color"
fi
echo "${color[$font_name_color]}"

echo -n "Column 2 background = "
if [[ $background_value_color == $default_bkgr_val_clr ]]; then
    echo -n "default"
else
    echo -n "$background_value_color"
fi
echo "${color[$background_value_color]}"

echo -n "Column 2 font color = "
if [[ $font_value_color == $default_font_val_clr ]]; then
    echo -n "default"
else
    echo -n "$font_value_color"
fi
echo "${color[$font_value_color]}"

echo -e "${bgr_name_clr}${font_name_clr}DATE${end} = ${bgr_value_color}${font_value_clr}$DATE${end}"
echo -e "${bgr_name_clr}${font_name_clr}UPTIME${end} = ${bgr_value_color}${font_value_clr}$UPTIME${end}"
echo -e "${bgr_name_clr}${font_name_clr}UPTIME_SEC${end} = ${bgr_value_color}${font_value_clr}$UPTIME_SEC${end}"
echo -e "${bgr_name_clr}${font_name_clr}IP${end} = ${bgr_value_color}${font_value_clr}$IP${end}"
echo -e "${bgr_name_clr}${font_name_clr}MASK${end} = ${bgr_value_color}${font_value_clr}$MASK${end}"
echo -e "${bgr_name_clr}${font_name_clr}GATEWAY${end} = ${bgr_value_color}${font_value_clr}$GATEWAY${end}"
echo -e "${bgr_name_clr}${font_name_clr}RAM_TOTAL${end} = ${bgr_value_color}${font_value_clr}$RAM_TOTAL${end}"
echo -e "${bgr_name_clr}${font_name_clr}RAM_USER${end} = ${bgr_value_color}${font_value_clr}$RAM_USER${end}"
echo -e "${bgr_name_clr}${font_name_clr}RAM_FREE${end} = ${bgr_value_color}${font_value_clr}$RAM_FREE${end}"
echo -e "${bgr_name_clr}${font_name_clr}SPACE_ROOT${end} = ${bgr_value_color}${font_value_clr}$SPACE_ROOT${end}"
echo -e "${bgr_name_clr}${font_name_clr}SPACE_ROOT_USED${end} = ${bgr_value_color}${font_value_clr}$SPACE_ROOT_USED${end}"
echo -e "${bgr_name_clr}${font_name_clr}SPACE_ROOT_FREE${end} = ${bgr_value_color}${font_value_clr}$SPACE_ROOT_FREE${end}"

exit 0

