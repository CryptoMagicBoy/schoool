#!/bin/bash

case $1 in
    1)export backname_color="\033[47m";;
    2)export backname_color="\033[41m";;
    3)export backname_color="\033[42m";;
    4)export backname_color="\033[44m";;
    5)export backname_color="\033[45m";;
    6)export backname_color="\033[40m";;
esac

case $2 in
    1)export fontname_color="\033[37m";;
    2)export fontname_color="\033[31m";;
    3)export fontname_color="\033[32m";;
    4)export fontname_color="\033[34m";;
    5)export fontname_color="\033[35m";;
    6)export fontname_color="\033[30m";;
esac

case $3 in
    1)export backvalue_color="\033[47m";;
    2)export backvalue_color="\033[41m";;
    3)export backvalue_color="\033[42m";;
    4)export backvalue_color="\033[44m";;
    5)export backvalue_color="\033[45m";;
    6)export backvalue_color="\033[40m";;
esac

case $4 in
    1)export fontvalue_color="\033[37m";;
    2)export fontvalue_color="\033[31m";;
    3)export fontvalue_color="\033[32m";;
    4)export fontvalue_color="\033[34m";;
    5)export fontvalue_color="\033[35m";;
    6)export fontvalue_color="\033[30m";;
esac

export clean="\e[0m"

chmod +x output.sh
./output.sh

exit 0
