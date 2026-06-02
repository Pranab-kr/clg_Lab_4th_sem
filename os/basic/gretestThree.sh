#!/bin/bash

echo "Enter first number:"
read a

echo "Enter second number:"
read b

echo "Enter third number:"
read c

if [ $a -ge $b ] && [ $a -ge $c ]
then
    echo "$a is greatest"
elif [ $b -ge $a ] && [ $b -ge $c ]
then
    echo "$b is greatest"
else
    echo "$c is greatest"
fi
