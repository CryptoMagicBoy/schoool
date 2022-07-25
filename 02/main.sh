#!/bin/bash

value=$3
value=${value::${#value} - 2}
let size_r=${value}*1024
size_r="${size_r}kb"

export start_time_in_seconds="$(date +%s)"
export start_time="$(date +%H:%M:%S)"

function random {
    echo $(($1 + $RANDOM % $2))
}

script_file_path=$(pwd)/../01/main.sh
test_file_date=$(date +"%d%m%y")

sudo touch /log.log
sudo chown $(whoami) /log.log

for (( i = 0; i > -1; i++ ))
do
    state=$((0 + $RANDOM % 2))
    if (( state != 0 ))
    then
    	pr=$(ls -d | wc -l)
    	if (( pr==1 )) ; then
    		cd /
    	fi
        dirs_quantity=$(ls -d */ | cut -f1 -d'/' | grep -vE "^.+_($test_file_date)$" | wc -l)
        if (( $dirs_quantity ))
        then
            random_dir_index=$(random 1 $dirs_quantity)
            dir_name=$(ls -d */ | cut -f1 -d'/' | grep -vE "^.+_($test_file_date)$" | awk -v var="${random_dir_index}" 'BEGIN{ RS = "" ; FS = "\n" } {print $var}')
            abspath=$(pwd)/$dir_name/
            random_papka=$(random 1 10)
            random_file=$(random 1 10)
            $script_file_path $abspath ${random_papka} $1 ${random_file} $2 $size_r
            if [[ $(echo $?) -eq 1 ]] ; then
            echo "DONE"
                break
            fi
            cd / 
        else
            cd /
        fi
    else
        cd /
    fi
done
/home/estaedmo/monitoring/02/falloc.sh
exit 0

