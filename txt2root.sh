#!/bin/sh
ls -l Data/Cosmics | grep -i $1 | \
awk '{print substr($NF,0,length($NF))}' > RunLists/List-Cosmics-$1.txt
python makeTree.py - -i RunLists/List-Cosmics-$1.txt -d Data/Cosmics
