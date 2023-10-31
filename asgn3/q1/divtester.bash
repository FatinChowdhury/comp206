#!/bin/bash

# this thing should have a bunch of testers

# first test: display "Test 1: not divisible & not increasing"
# then run program with numbers "10 5 7" (use redirection to replace keyboard input)
# (redirection: gcc divisible.c 2> smth?)
# Following output from command itself, display "Expected output message: Not divisible & Not increasing

# second test: display "Test 2: divisible & not increasing"
# run program with numbers "5 20 10".
# Following output from command itself, depending on error code, display "Exited with expected return code: 2"
# or "Exited with unexpected return code: X (Expected 2)"; X is the error code in your C program

# can put as many tests as you want.
echo "Test 1: not divisible & not increasing"
OUTPUT=$(echo "10 5 7" | ./divisible)
EXPECTED="Not divisible & Not increasing"

[[ $EXPECTED==$OUTPUT ]]

