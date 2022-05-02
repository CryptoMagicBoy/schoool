#!/bin/bash

START=$(date +%s%N)

if [[ $# != 1 || $1 =~ [^/]$ ]] ; then
    echo "Incorrect input"
    exit 1
fi

dirname="$1"

if [[ -z $(find $dirname) ]] ; then
    echo "Directory doesn't exist"
    exit 1
fi
source init_func.sh

total_number_of_folders $dirname
top_5_folders $dirname
total_number_of_files $dirname
amount_of_files_by_types $dirname
top_10_files $dirname
top_10_executable_files $dirname

END=$(date +%s%N)
DIFF=$(( $END - $START ))
echo -n "Script execution time (in seconds) = "
echo "scale=2; $DIFF / 1000000000" | bc
