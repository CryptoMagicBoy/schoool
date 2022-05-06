#!/bin/bash

case $back_name in
    1)
        export backname_color="\033[47m"
        export back1_color="white"
        ;;
    2)
        export backname_color="\033[41m"
        export back1_color="red"
        ;;
    3)
        export backname_color="\033[42m"
        export back1_color="green"
        ;;
    4)
        export backname_color="\033[44m"
        export back1_color="blue"
        ;;
    5)
        export backname_color="\033[45m"
        export back1_color="purple"
        ;;
    6)
        export backname_color="\033[40m"
        export back1_color="black"
        ;;
esac

case $font_name in
    1)
        export fontname_color="\033[37m"
        export font1_color="white"
        ;;
    2)
        export fontname_color="\033[31m"
        export font1_color="red"
        ;;
    3)
        export fontname_color="\033[32m"
        export font1_color="green"
        ;;
    4)
        export fontname_color="\033[34m"
        export font1_color="blue"
        ;;
    5)
        export fontname_color="\033[35m"
        export font1_color="purple"
        ;;
    6)
        export fontname_color="\033[30m"
        export font1_color="black"
        ;;
esac

case $back_value in
    1)
        export backvalue_color="\033[47m"
        export back2_color="white"
        ;;
    2)
        export backvalue_color="\033[41m"
        export back2_color="red"
        ;;
    3)
        export backvalue_color="\033[42m"
        export back2_color="green"
        ;;
    4)
        export backvalue_color="\033[44m"
        export back2_color="blue"
        ;;
    5)
        export backvalue_color="\033[45m"
        export back2_color="purple"
        ;;
    6)
        export backvalue_color="\033[40m"
        export back2_color="black"
        ;;
esac

case $font_value in
    1)
        export fontvalue_color="\033[37m"
        export font2_color="white"
        ;;
    2)
        export fontvalue_color="\033[31m"
        export font2_color="red"
        ;;
    3)
        export fontvalue_color="\033[32m"
        export font2_color="green"
        ;;
    4)
        export fontvalue_color="\033[34m"
        export font2_color="blue"
        ;;
    5)
        export fontvalue_color="\033[35m"
        export font2_color="purple"
        ;;
    6)
        export fontvalue_color="\033[30m"
        export font2_color="black"
        ;;
esac

export clean="\e[0m"

chmod +x output.sh
./output.sh $1 $2 $3 $4 $5

exit 0
