echo "Enter how many process: "
read n

declare -a wt
declare -a tat
declare -a pid
declare -a bt

for ((i = 0; i < n; i++)); do
  pid[$i]=$((i + 1))
  echo "Enter the BT for P$((i + 1)): "
  read bt[$i]
done

wt[0]=0

for ((i = 1; i < n; i++)); do
  wt[$i]=$((bt[i-1] + wt[i-1]))
done

for ((i = 0; i < n; i++)); do
  tat[$i]=$((bt[i] + wt[i]))
done

echo -e "\nPID\tBT\tWT\tTAT\n"

total_wt=0
total_tat=0

for ((i = 0; i < n; i++)); do
  echo -e "P${pid[$i]}\t${bt[$i]}\t${wt[$i]}\t${tat[$i]}"
  total_wt=$((total_wt + wt[i]))
  total_tat=$((total_tat + tat[i]))
done

avg_wt=$(bc <<<"scale=2; $total_wt/$n")
avg_tat=$(bc <<<"scale=2; $total_tat/$n")

echo -e "\nAvg_WT: $avg_wt"
echo -e "\nAvg_TAT: $avg_tat"
