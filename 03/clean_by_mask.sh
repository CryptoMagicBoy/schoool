#! /bin/bash

echo "Input mask: "
read mask
sudo find / -type f -name $mask -delete
exit 0
