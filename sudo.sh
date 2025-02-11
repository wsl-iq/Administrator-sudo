#!/bin/bash

# Requires Administrator (sudo)
if [ "$EUID" -ne 0 ]; then
    echo "Program requires Administrator privileges. Restarting..."
    exec sudo "$0" "$@"
    exit
fi

# Shell
cd "$(dirname "$0")"

# Run Program main
echo "Welcome, I'm Mohammed Al-Baqer"

# Simulate program execution
if ! true; then
    echo "Failed to execute the program."
    read -p "Press Enter to exit..."
fi
