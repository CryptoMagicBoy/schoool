#!/bin/bash

if [[ $# != 0 ]] ; then
    echo "Incorrect input"
else
    chmod +x output.sh
    ./output.sh
    chmod +x fill_to_file.sh
    ./fill_to_file.sh
fi
