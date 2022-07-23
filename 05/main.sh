#! /bin/bash

if (( $1 == 1 )) ; then
    awk {'print | "sort -k8"'} ../04/*.log
elif (( $1 == 2 )) ; then
    awk {'print $1 | "sort -u"'} ../04/*.log
elif (( $1 == 3 )) ; then
    awk '/ ([4-5]0[0-4]) /{ print }' ../04/*.log
elif (( $1 == 4 )) ; then
    awk '/ ([4-5]0[0-4]) /{ print $1 | "sort -u" }' ../04/*.log
fi

