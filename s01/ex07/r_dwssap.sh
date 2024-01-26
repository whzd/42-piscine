#!/bin/bash
cat /etc/passwd | grep -o '^[^#]*' | awk 'NR%2==0' | cut -d ':' -f1 | rev | sort -r | sed "$FT_LINE1,$FT_LINE2!d" | tr '\n' ' ' | sed 's/ /, /g' | sed "s/, $/./"
