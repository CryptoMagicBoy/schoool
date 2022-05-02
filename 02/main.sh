#!/bin/bash

if [[ $# != 0 ]] ; then
    echo "Incorrect input"
else
    chmod +x system_info.sh
    ./system_info.sh
fi
