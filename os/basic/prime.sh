#!/bin/bash

echo "Enter a number:"
read n

flag=1

if [ $n -le 1 ]
then
    flag=0
else
    for ((i=2; i<n; i++))
    do
        if [ $((n % i)) -eq 0 ]
        then
            flag=0
            break
        fi
    done
fi

if [ $flag -eq 1 ]
then
    echo "$n is a Prime Number"
else
    echo "$n is Not a Prime Number"
fi
