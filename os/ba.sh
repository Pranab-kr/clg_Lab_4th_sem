#!/bin/bash

echo "Enter number of processes:"
read n

echo
echo "Enter number of resources:"
read m

declare -A alloc
declare -A max
declare -A need
declare -a avail
declare -a finish
declare -a safe

echo
echo "Enter Allocation Matrix:"

for ((i=0; i<n; i++))
do
    for ((j=0; j<m; j++))
    do
        read alloc[$i,$j]
    done
done

echo
echo "Enter Maximum Matrix:"

for ((i=0; i<n; i++))
do
    for ((j=0; j<m; j++))
    do
        read max[$i,$j]
    done
done

echo
echo "Enter Available Resources:"

for ((i=0; i<m; i++))
do
    read avail[$i]
done

# Calculate Need Matrix
for ((i=0; i<n; i++))
do
    finish[$i]=0

    for ((j=0; j<m; j++))
    do
        need[$i,$j]=$(( ${max[$i,$j]} - ${alloc[$i,$j]} ))
    done
done

count=0

while [ $count -lt $n ]
do
    found=0

    for ((i=0; i<n; i++))
    do
        if [ ${finish[$i]} -eq 0 ]
        then
            possible=1

            for ((j=0; j<m; j++))
            do
                if [ ${need[$i,$j]} -gt ${avail[$j]} ]
                then
                    possible=0
                    break
                fi
            done

            if [ $possible -eq 1 ]
            then
                for ((k=0; k<m; k++))
                do
                    avail[$k]=$(( ${avail[$k]} + ${alloc[$i,$k]} ))
                done

                safe[$count]="P$i"
                finish[$i]=1
                count=$((count+1))
                found=1
            fi
        fi
    done

    if [ $found -eq 0 ]
    then
        break
    fi
done

echo

if [ $count -eq $n ]
then
    echo "System is in SAFE state"
    echo -n "Safe Sequence: "

    for ((i=0; i<n; i++))
    do
        echo -n "${safe[$i]}"

        if [ $i -lt $((n-1)) ]
        then
            echo -n " -> "
        fi
    done

    echo
else
    echo "System is NOT in SAFE state"
fi

# 5
# 3
#
# 0
# 1
# 0
# 2
# 0
# 0
# 3
# 0
# 2
# 2
# 1
# 1
# 0
# 0
# 2
#
# 7
# 5
# 3
# 3
# 2
# 2
# 9
# 0
# 2
# 2
# 2
# 2
# 4
# 3
# 3
#
# 3
# 3
# 2
