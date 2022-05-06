#!/bin/bash

START=$(date +%s%N)

cd

if [[ $# != 1 || ! ($1 =~ /$) || ! (-d $1) ]] ; then
    echo Incorrect input or no directory
    exit 1
fi

cd /home/estaedmo/linmonitoring/05

source script.sh

total_number_of_folders $1
top_5_huge_folders $1
total_number_of_files $1
files $1
top_10_huge_files $1
top_10_executable_huge_files $1

END=$(date +%s%N)
let TIME=$(( $END - $START ))
echo -n "Script execution time (in seconds) = "
echo "scale=2; $TIME / 1000000000" | bc
exit 0
