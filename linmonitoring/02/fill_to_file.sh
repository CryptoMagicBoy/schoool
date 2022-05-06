#!/bin/bash

read -p "Write to file? (Y/N)" otv

if [[ $otv =~ [Yy] ]]; then
    filename="$(date +%d_%m_%y_%H_%M_%S.status)"
    ./output.sh > $filename
fi
