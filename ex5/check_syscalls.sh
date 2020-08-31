#!/bin/bash

####################
# Lab 1 Exercise 5
# Name: Chong Zi Kang
# Student No: A0189930R
# Lab Group: T10
####################

echo "Printing system call report"

# compile file
gcc -std=c99 pid_checker.c -o ex5

# use strace to get report
strace -c ./ex5