#!/bin/bash

echo "Test 1: mary and ramy"
output=$(./anagram mary ramy)
echo "$output"
echo "Expected output message: Anagram"

echo "Test 2: bob and lary"
output=$(./anagram bob lary)
return_code=$?
if [ $return_code -eq 1 ]; then
        echo "$output"
        echo "Exited with expected return code: 1"
else
        echo "$output"
        echo "Exited with unexpected return code: $return_code (Expected 1)"

