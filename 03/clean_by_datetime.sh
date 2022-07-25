#! /bin/bash

echo "Input start date: (YYYY-MM-DD hh:mm:ss)"
read start_date
echo "Input end date: (YYYY-MM-DD hh:mm:ss)"
read end_date
find / -type f -newermt $start_date -not -newermt $end_date -ls
exit 0
