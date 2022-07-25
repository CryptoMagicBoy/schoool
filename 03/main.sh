#! /bin/bash

cleaning_method=$1

if [[ $# -ne 1 ]]
then
    echo "Incorrect input."
    exit 1
fi

method=$1

if [[ $method == 1 ]]
then
    ./clean_by_log.sh
elif [[ $method == 2 ]]
then
    ./clean_by_datetime.sh
elif [[ $method == 3 ]]
then
    ./clean_by_mask.sh
else
    echo "Incorrect input"
fi



