#!/bin/bash

echo "Enter number of processes:"
read n

declare -a bt
declare -a wt
declare -a tat
declare -a pid

for ((i = 0; i < n; i++)); do
  pid[$i]=$((i + 1))
  echo "Enter burst time for process $((i + 1)):"
  read bt[$i]
done

# Sorting based on burst time
for ((i = 0; i < n; i++)); do
  for ((j = i + 1; j < n; j++)); do
    if [ ${bt[$i]} -gt ${bt[$j]} ]; then
      temp=${bt[$i]}
      bt[$i]=${bt[$j]}
      bt[$j]=$temp

      temp=${pid[$i]}
      pid[$i]=${pid[$j]}
      pid[$j]=$temp
    fi
  done
done

wt[0]=0

# Calculate waiting time
for ((i = 1; i < n; i++)); do
  wt[$i]=$((wt[$i-1] + bt[$i-1]))
done

# Calculate turnaround time
for ((i = 0; i < n; i++)); do
  tat[$i]=$((wt[$i] + bt[$i]))
done

echo -e "\nProcess\tBT\tWT\tTAT"
total_wt=0
total_tat=0

for ((i = 0; i < n; i++)); do
  echo -e "P${pid[$i]}\t${bt[$i]}\t${wt[$i]}\t${tat[$i]}"
  total_wt=$((total_wt + wt[$i]))
  total_tat=$((total_tat + tat[$i]))
done

avg_wt=$(echo "scale=2; $total_wt / $n" | bc)
avg_tat=$(echo "scale=2; $total_tat / $n" | bc)

echo -e "\nAverage Waiting Time: $avg_wt"
echo "Average Turnaround Time: $avg_tat"
#
# output
# Enter number of processes:
# 4
#
# Enter burst time for process 1:
# 6
#
# Enter burst time for process 2:
# 8
#
# Enter burst time for process 3:
# 7
#
# Enter burst time for process 4:
# 3
# Process	BT	WT	TAT
# P4	3	0	3
# P1	6	3	9
# P3	7	9	16
# P2	8	16	24
#
# Average Waiting Time: 7.00
# Average Turnaround Time: 13.00
