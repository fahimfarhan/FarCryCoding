#!/bin/dash

## v1: print values from a list
echo "----this is v1----\n";

for i in 1 2 3 4 'a' 'ricardo milos' "aye papi"
do
  echo "current item = $i";
done;

## v2: basically for(int i=0; i<N; i++), warning this is a bash feature, unfortunately not dash :'( 

echo "----this is v2----\n";
for j in {1..3..7}
do 
  echo $j;
done;

echo "----this is v3----\n";


k=80
while [ "$k" -le 101 ]; do
    # amixer cset numid=1 "$i%"
    # sleep 60
    echo "$k"
    k=$(( k + 1 ))
done
