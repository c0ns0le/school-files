#!/bin/sh

NO_TESTS=9
EXEC=tema2
TIMEOUT=6
TEST_POINTS=10

TOTAL=0

# Check a single test and add the result to the total score. This function
# should _always_ receive a test number as the first and only argument
check_test()
{
    test_no=$1

    echo
    echo -n "Test: $test_no ...................... "

    # Get the input and ref files for the current test
    input_path="inputs/$test_no"
    ref_path="ref/$test_no"
    files=$(ls $input_path)

    cp $input_path/* .

    # Run the test, also consider the timeout
    (time timeout $TIMEOUT ./$EXEC <in.txt >out.txt) 2>time.err
    if test $? -eq 124; then
        echo "TIMEOUT"

        rm -f $files
        rm -f out.txt
        rm -f time.err
        continue
    fi

    # Clean up input files
    rm -f $files

    # Check the result
    diff -bB -i "$ref_path/out.ref" out.txt 2>&1 1> my_diff
    if test $? -eq 0; then
        echo "PASS"
        cat time.err
        TOTAL=$(expr $TOTAL + $TEST_POINTS)
    else
        echo "FAILED"
        echo "Diff result:"
        cat time.err
        cat my_diff | tail -n 10
    fi

    # Clean up
    rm -f my_diff
    rm -f out.txt
    rm -f time.err

    echo
}


# Check if the the exec exist
if test ! -x $EXEC; then
    echo "File Missing"
    exit 1
fi

# Fail if more than one arg is recieved
if test $# -gt 1; then
    echo "Usage: ./check [no_test]"
    exit 1
fi

# Fail if the first arg is not a valid test number [1-9]
if test $# -eq 1 &&  ! (test $1 -eq $1 2>/dev/null && test $1 -le 9 &&
    test $1 -ge 1) ; then

    echo "Usage: ./check [no_test]"
    exit 1
fi

# If one valid arg is recieved, only run the specified test
if test $# -eq 1 && test $1 -eq $1 && test $1 -ge 0 && test $1 -le 9; then
    check_test $1
    exit 0
fi

# If no arg, run all tests
for test_no in $(seq $NO_TESTS); do
    check_test $test_no
done

# And the restul is ...
echo "TOTAL: $TOTAL/$(expr $TEST_POINTS \* $NO_TESTS)"
