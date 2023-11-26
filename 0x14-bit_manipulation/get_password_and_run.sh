#!/bin/bash
# Get password script

echo -e
echo -e "Fetching password file ..."
echo -e

curl https://raw.githubusercontent.com/alx-tools/0x13.c/master/101-password -o 101-password

# Run the crackme3 program with the password
./crackme3 $(cat 101-password) "Hol"
