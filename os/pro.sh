#!/bin/bash

buffer_file="buffer.txt"
lock_file="lock.lock"
max_size=5

echo "" >$buffer_file

producer() {
  for ((i = 1; i <= 5; i++)); do
    (
      flock -x 200

      count=$(wc -l <$buffer_file)

      if [ $count -lt $max_size ]; then
        item=$RANDOM

        echo $item >>$buffer_file

        echo "Produced : $item"
      else
        echo "Buffer Full, Producer waiting..."
      fi

    ) 200>$lock_file

    sleep 1
  done
}

consumer() {
  for ((i = 1; i <= 5; i++)); do
    (
      flock -x 200

      if [ -s $buffer_file ]; then
        item=$(head -n 1 $buffer_file)

        tail -n +2 $buffer_file >temp
        mv temp $buffer_file

        echo "Consumed : $item"
      else
        echo "Buffer Empty, Consumer waiting..."
      fi

    ) 200>$lock_file

    sleep 2
  done
}

producer &
consumer &

wait

echo "Process Finished"
