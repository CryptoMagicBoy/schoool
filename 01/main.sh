#!/bin/bash
if [[ $# -ne 1 || "$1" =~ ^[+-]?[0-9]+\.?[0-9]+$ ]] ; then
    echo "Incorrect input"
    exit 1
else
    echo "$1"
fi
exit 0
