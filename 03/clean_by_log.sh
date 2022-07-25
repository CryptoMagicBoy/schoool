#! /bin/bash

while IFS= read -r line
do
  files=$(echo $line | grep '/' | awk '{print $1}')
  echo $files
  sudo rm -rf $files
done < /log.log
sudo rm /log.log
exit 0
