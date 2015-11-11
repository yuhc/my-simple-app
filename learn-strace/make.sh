#!/bin/sh

echo "# COMPILING TRACE_ME"
gcc -o trace_me trace_me.c
echo "# STRACING TRACE_ME"
strace -s 2000 -f ./trace_me
