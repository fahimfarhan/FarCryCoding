#!/bin/dash

read -r x
read -r y

sum=$((x + y))
echo "$sum"

minus=$((x-y))
echo "$minus"

product=$((x*y))
echo "$product"

quotient=$((x/y))
echo "$quotient"
