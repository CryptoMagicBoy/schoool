#!/bin/bash

IFS=$'\n'

function total_number_of_folders() {
    echo "Total number of folders (including all nested ones) = $(sudo find $1 -type d | wc -l)"
}

function total_number_of_files() {
    echo "Total number of files = $(sudo find $1 -type f | wc -l)"
}

function files() {
    echo "Number of:"
    echo "Configuration files (with the .conf extension) = $(sudo find $1 -type f -name "*.conf" | wc -l)"
    echo "Text files = $(sudo find $1 -type f -name "*.txt" | wc -l)"
    echo "Executable files = $(sudo find $1 -type f -executable | wc -l)"
    echo "Log files (with the extension .log) = $(sudo find $1 -type f -name "*.log" | wc -l)"
    echo "Archive files = $(sudo find $1 -type f -name "*.tar" -or -name "*.zip" -or -name "*.7z" -or -name "*.ace" -or -name "*.jar" -or -name "*.gz" -or -name "*.gzip" -or -name "*.stix"| wc -l)"
    echo "Symbolic links = $(sudo find $1 -type l | wc -l)"
}

function top_5_huge_folders() {
    echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
    folders=($(sudo du -h $1 | sort -hr | head -n 5 | awk '{print" - "$2", "$1}'))
    for (( i = 0; i < 5; i++ )) ; do
        if [[ -z ${folders[i]} ]] ; then
            break
        fi
        echo "$(( i + 1 )) ${folders[i]}"
    done
}

function top_10_huge_files() {
    echo "TOP 10 files of maximum size arranged in descending order (path, size and type):"
    files=($(sudo find $1 -type f -exec du -h '{}' \; | sort -hr | head -n 10))
    for (( i = 0; i < 10; i++ )) ; do
        if [[ -z ${files[i]} ]] ; then
            break
        fi
        path=$(echo "${files[i]}" | awk '{printf $2}')
        size=$(echo "${files[i]}" | awk '{printf $1}')
        type=$(file -b $path | sed 's/,.*//')
        echo "$(( i + 1 )) - $path, $size, $type"
    done
}

function top_10_executable_huge_files() {
    echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file)"
    files=($(sudo find $1 -type f -executable -exec du -h '{}' \; | sort -hr | head -n 10))
    for (( i = 0; i < 10; i++ )) ; do
        if [[ -z ${files[i]} ]] ; then
            break
        fi
        path=$(echo "${files[i]}" | awk '{printf $2}')
        size=$(echo "${files[i]}" | awk '{printf $1}')
        md5=$(md5sum $path | awk '{print $1}')
        echo "$(( i + 1 )) - $path, $size, $md5"
    done
}
