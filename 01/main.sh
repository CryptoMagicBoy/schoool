#!/bin/bash

if [[ $# -ne 6 ]] ; then
    echo "Incorrect input"
    exit 1
else
    export file_date=$(date +"%d%m%y")
    export path=$1
    export k_papka=$2
    export name_papka=$3
    export k_file=$4
    export name_file=$5
    export size_file=$6
    export const_space=1048576
    if ! [ -d ${path} ] ; then
        echo "Incorrect pwd"
        exit 1
    fi
    if [[ ! (${k_papka} =~ ^[1-9][0-9]*$) ]] ; then
        echo "Incorrect input value 2"
        exit 1
    fi
    if [[ ! (${name_papka} =~ ^[a-zA-Z]{1,7}$) ]] ; then
        echo "Incorrect input value 3"
        exit 1
    fi
    if [[ ! (${k_file} =~ ^[1-9][0-9]*$) ]] ; then
        echo "Incorrect input value 4"
        exit 1
    fi
    if [[ ! (${name_file} =~ ^[a-zA-Z]{1,7}\.[a-zA-Z]{1,3}$) ]] ; then
        echo "Incorrect input value 5"
        exit 1
    fi
    if [[ ! (${size_file} =~ ^[1-9][0-9]{0,2}(kb)$) ]] ; then
        echo "Incorrect input value 6"
        exit 1
    fi
    export pwd_log="$(pwd)/log.log"
    chmod +x gen_files.sh
    ./gen_files.sh
fi
exit 0
