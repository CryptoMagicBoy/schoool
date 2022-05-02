#!/bin/bash

export HOSTNAME="$(cat /etc/hostname)"
export TIMEZONE="$(cat /etc/timezone) UTC $(date "+%Z")"
export USER="$(whoami)"
export OS="$(cat /etc/issue | awk '{printf "%s %s", $1,$2}')"
export DATE="$(date +"%d %b %Y %T")"
export UPTIME="$(uptime -p | awk '{print $2,$3}')"
export UPTIME_SEC="$(cat /proc/uptime | awk '{print int ($1) " sec"}')"
export IP="$(hostname -I | awk '{print $1}')"
export MASK="$(ip -br a | awk '/UP/{print $3}' | awk -F '/' '{print $2}')"
export GATEWAY="$(ip r | awk '/default/{print $3}')"
export RAM_TOTAL="$(free -m | awk '/Mem:/{printf "%.3f GB", $2/1024}')"
export RAM_USER="$(free -m | awk '/Mem:/{printf "%.3f GB", $3/1024}')"
export RAM_FREE="$(free -m | awk '/Mem:/{printf "%.3f GB", $4/1024}')"
export SPACE_ROOT="$(df /root/ | awk '/dev/ {printf "%.2f MB", $2/1024}')"
export SPACE_ROOT_USED="$(df /root/ | awk '/dev/ {printf "%.2f MB", $3/1024}')"
export SPACE_ROOT_FREE="$(df /root/ | awk '/dev/ {printf "%.2f MB", $4/1024}')"
chmod +x print.sh
./print.sh
