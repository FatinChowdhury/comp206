#!/bin/bash

echo "Test 1: not divisible & not increasing"
output=$(echo "10 5 7" | ./divisible)
echo "$output"
echo "Expected output message: Not divisible & Not increasing"


echo "Test 2: divisible & not increasing"
output=$(echo "3 6 9" | ./divisible)
return_code=$?
if [ $return_code -eq 2 ]; then
        echo "$output"
        echo "Exited with expected return code: 2"
else
        echo "$output"
        echo "Exited with unexpected return code: $return_code (Expected 2)"
fi
