#!/bin/bash

echo 1 >semaphore.txt

wait_semaphore() {

  while true; do
    value=$(cat semaphore.txt)

    if [ "$value" -gt 0 ]; then
      echo 0 >semaphore.txt
      echo "Process $$ entered critical section"
      break
    else
      echo "Process $$ waiting..."
      sleep 1
    fi
  done

}

signal_semaphore() {

  echo 1 >semaphore.txt
  echo "Process $$ exited critical section"

}

wait_semaphore

echo "Process $$ is working in critical section"
sleep 3

signal_semaphore

# Process 4433 entered critical section
# Process 4433 is working in critical section
# Process 4433 exited critical section
