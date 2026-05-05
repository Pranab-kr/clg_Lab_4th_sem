#!/bin/bash

echo "Enter number of processes:"
read n

declare -a bt
declare -a wt
declare -a tat
declare -a pid

# Input
for ((i = 0; i < n; i++)); do
  pid[$i]=$((i + 1))
  echo "Enter burst time for process $((i + 1)):"
  read bt[$i]
done

# First process waiting time = 0
wt[0]=0

# Calculate waiting time
for ((i = 1; i < n; i++)); do
  wt[$i]=$((wt[i-1] + bt[i-1]))
done

# Calculate turnaround time
for ((i = 0; i < n; i++)); do
  tat[$i]=$((wt[i] + bt[i]))
done

# Output
echo -e "\nProcess\tBT\tWT\tTAT"

total_wt=0
total_tat=0

for ((i = 0; i < n; i++)); do
  echo -e "P${pid[$i]}\t${bt[$i]}\t${wt[$i]}\t${tat[$i]}"
  total_wt=$((total_wt + wt[i]))
  total_tat=$((total_tat + tat[i]))
done

# Averages
avg_wt=$(echo "scale=2; $total_wt / $n" | bc)
avg_tat=$(echo "scale=2; $total_tat / $n" | bc)

echo -e "\nAverage Waiting Time: $avg_wt"
echo "Average Turnaround Time: $avg_tat"
