echo "Enter the num of prcess: "
read n

declare -a bt
declare -a wt
declare -a tat
declare -a pid

for ((i = 0; i < n; i++)); do
  pid[$i]=$((i + 1))
  echo -e "Enter the bt for p$((i + 1)): "
  read bt[$i]
done

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

for ((i = 1; i < n; i++)); do
  wt[$i]=$((wt[i-1] + bt[i-1]))
done

for ((i = 0; i < n; i++)); do
  tat[$i]=$((wt[i] + bt[$i]))
done

echo -e "\npid\tbt\twt\ttat\n"

total_wt=0
total_tat=0

for ((i = 0; i < n; i++)); do
  echo -e "p${pid[$i]}\t${bt[$i]}\t${wt[$i]}\t${tat[$i]}\n"
  total_wt=$((total_wt + ${wt[$i]}))
  total_tat=$((total_tat + ${tat[$i]}))
done

avg_wt=$(echo "scale=2; $total_wt/$n" | bc)
avg_tat=$(echo "scale=2; $total_tat/$n" | bc)

echo -e "\nThe avg WT is: $avg_wt"
echo -e "\nThe avg TAT is: $avg_tat"
