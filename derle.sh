#!/bin/bash
echo "GSM Tracking System Compiling..."
gcc *.c -o gsm_system
if [ $? -eq 0 ]; then
    echo "Compilation successful! Running..."
    ./gsm_system
else
    echo "Compilation failed! Please make sure GCC is installed."
fi
