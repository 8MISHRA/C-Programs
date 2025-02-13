#!/bin/bash
set -e 
gcc foo.c -o foo
export PATH=$PATH:$PWD
VG="valgrind --leak-check=full --track-origins=yes "
$VG foo 1>_x 2>&1

grep "SUCCESS" _x 1>/dev/null 2>&1
