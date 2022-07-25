#!/bin/bash

end_time_in_seconds="$(date +%s)"
end_time="$(date +%H:%M:%S)"

execution_time=$(( $end_time_in_seconds - $start_time_in_seconds ))

echo "Start time: $start_time"
echo "End time: $end_time"
echo "Script execution time (in seconds) = $execution_time"

echo "Start time: $start_time" >> /log.log
echo "End time: $end_time" >> /log.log
echo "Execution time: $execution_time" >> /log.log
