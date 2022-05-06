#!/bin/bash

echo -e "${backname_color}${fontname_color}HOSTNAME${clean} = ${backvalue_color}${fontvalue_color}$(hostname)${clean}"
echo -e "${backname_color}${fontname_color}TIMEZONE${clean} = ${backvalue_color}${fontvalue_color}$(cat /etc/timezone) UTC $(date +%Z)${clean}"
echo -e "${backname_color}${fontname_color}USER${clean} = ${backvalue_color}${fontvalue_color}$(whoami)${clean}"
echo -e "${backname_color}${fontname_color}OS${clean} = ${backvalue_color}${fontvalue_color}$(hostnamectl | grep "Operating System" | awk '{print $3,$4,$5}')${clean}"
echo -e "${backname_color}${fontname_color}DATE${clean} = ${backvalue_color}${fontvalue_color}$(date -u | awk '{print $2,$3,$4,$5}')${clean}"
echo -e "${backname_color}${fontname_color}UPTIME${clean} = ${backvalue_color}${fontvalue_color}$(uptime -p | awk '{print $2,$3,$4,$5}')${clean}"
echo -e "${backname_color}${fontname_color}UPTIME_SEC${clean} = ${backvalue_color}${fontvalue_color}$(cat /proc/uptime | awk '{print int ($1), "sec"}')${clean}"
echo -e "${backname_color}${fontname_color}IP${clean} = ${backvalue_color}${fontvalue_color}$(hostname -I)${clean}"
echo -e "${backname_color}${fontname_color}MASK${clean} = ${backvalue_color}${fontvalue_color}$(ifconfig | grep "broadcast" | awk '{print $4}')${clean}"
echo -e "${backname_color}${fontname_color}GATEWAY${clean} = ${backvalue_color}${fontvalue_color}$(route -n | grep 'UG' | awk '{print $2}')${clean}"
echo -e "${backname_color}${fontname_color}RAM_TOTAL${clean} = ${backvalue_color}${fontvalue_color}$(free -m | awk '/Память:/{printf "%.3f GB", $2/1024}')${clean}"
echo -e "${backname_color}${fontname_color}RAM_USER${clean} = ${backvalue_color}${fontvalue_color}$(free -m | awk '/Память:/{printf "%.3f GB", $3/1024}')${clean}"
echo -e "${backname_color}${fontname_color}RAM_FREE${clean} = ${backvalue_color}${fontvalue_color}$(free -m | awk '/Память:/{printf "%.3f GB", $4/1024}')${clean}"
echo -e "${backname_color}${fontname_color}SPACE_ROOT${clean} = ${backvalue_color}${fontvalue_color}$(df /root -k | grep "/dev" | awk '{printf "%.2f MB", $2/1024}')${clean}"
echo -e "${backname_color}${fontname_color}SPACE_ROOT_USED${clean} = ${backvalue_color}${fontvalue_color}$(df /root -k | grep "/dev" | awk '{printf "%.2f MB", $3/1024}')${clean}"
echo -e "${backname_color}${fontname_color}SPACE_ROOT_FREE${clean} = ${backvalue_color}${fontvalue_color}$(df /root -k | grep "/dev" | awk '{printf "%.2f MB", $4/1024}')${clean}"

printf "\n"

if [ $5 = 0 ] ; then
    echo "Column 1 background = $1 ($back1_color)"
    echo "Column 1 font color = $2 ($font1_color)"
    echo "Column 2 background = $3 ($back2_color)"
    echo "Column 2 font color = $4 ($font2_color)"
else
    echo "Column 1 background = default (black)"
    echo "Column 1 font color = default (white)"
    echo "Column 2 background = default (red)"
    echo "Column 2 font color = default (blue)"
fi
