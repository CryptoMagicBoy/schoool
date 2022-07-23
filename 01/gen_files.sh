#!/bin/bash

for (( i = 0; i < (1024 * ${size_file::${#size_file} - 2}); i++ ))
do
    trash="a${trash}"
done
for (( a = 0; a < k_papka; a++ ))
do
    if [[ ${#name_papka} < 3 ]] ; then
        name_papka="${name_papka::1}${name_papka}"
        a=$((a-1))
    else
        name_papka="${name_papka::1}${name_papka}"
        sudo mkdir -p "${path}/${name_papka}_${file_date}"
        echo "${path}/${name_papka}_${file_date} $(date)" >> $pwd_log
        sudo chown $(whoami) "${path}/${name_papka}_${file_date}"
        cd "${path}/${name_papka}_${file_date}"
        for (( b = 0; b < k_file; b++ ))
        do
            if [[ `expr index "$name_file" '.'` < 4 ]] ; then
                name_file="${name_file::1}${name_file}"
                b=$((b-1))
            else
                name_file="${name_file::1}${name_file}"
                index=`expr index "$name_file" '.'`
                free_space_size=$(df -k | grep "/$" | awk '{print($4)}')
                free_space=$((free_space_size-${size_file::${#size_file}-2}))
                if [ $free_space -lt $const_space ] ; then
                    echo "Not space free"
                    exit 0
                else
                    sudo echo ${trash} > "${name_file::index-1}_${file_date}${name_file:index - 1}"
                    sudo chown $(whoami) "${name_file::index-1}_${file_date}${name_file:index - 1}"
                    echo "${path}/${name_papka}_${file_date}/${name_file::index-1}_${file_date}${name_file:index - 1} $(date) ${size_file}" >> $pwd_log
                fi
            fi
        done
        cd ..
    fi
done
