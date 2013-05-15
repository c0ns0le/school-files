#!/bin/bash

SCORE=0

make sort
for i in {1..10}
do
    testing/gen "test"$i".in" $(( (i + 2) * 10)) $((i * 2)) $(((i + 5) * (i + 10)))
    ./p4 <"test"$i".in" >"test"$i".out"
    testing/test "test"$i".out" > result
    RESULT=$(cat result)
    rm result
    if [ $RESULT -eq 1 ]
    then
        echo "Test" $i": PASSED!"
        SCORE=$(($SCORE + 1))
    else
        echo "Test" $i": FAILED!"
    fi
    echo "Score: "$SCORE"/10"
    echo

    rm "test"$i".in"
    rm "test"$i".out"
done

echo "Final score: "$SCORE"/10"
make clean-sort

