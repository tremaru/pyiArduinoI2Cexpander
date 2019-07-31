#!/bin/bash
#script for recomening C to Python 
#cutting extension from file passed to script
OUTPUT="$(echo $1 | cut -d "." -f 1)"
#deleting all instances of octothorp, replacing all instances of doubleslash with octothorp, replacing all semicolons with blank
awk '{ gsub("#",""); print $0}' $1 | awk '{ gsub("//","#"); print $0}' | awk '{ gsub(";"," "); print $0}' > $OUTPUT.py
