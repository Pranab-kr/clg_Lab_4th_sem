#!/bin/bash

echo "Enter a number:"
read n

temp=$n
sum=0

while [ $temp -gt 0 ]
do
    digit=$((temp % 10))
    sum=$((sum + digit * digit * digit))
    temp=$((temp / 10))
done

if [ $sum -eq $n ]
then
    echo "$n is an Armstrong Number"
else
    echo "$n is Not an Armstrong Number"
fi
# Enter a number:
# 153
# 153 is an Armstrong Number
