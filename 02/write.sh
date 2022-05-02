#!/bin/bash

read -p "Write to file? (Yy/N)" log

if [[ $log =~ [Yy] ]]; then
    name="$(date +%d_%m_%y_%H_%M_%S.status)"
    ./print.sh > $name
fi
