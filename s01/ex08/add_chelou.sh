#!/bin/bash
VAL1=$(echo "$FT_NBR1" | sed "s/'/0/g" | sed 's/\\/1/g' | sed 's/"/2/g' | sed 's/?/3/g' | sed 's/!/4/g')
VAL2=$(echo "$FT_NBR2" | tr mrdoc '01234')
RES=$(echo "obase=13; ibase=5; $VAL1 + $VAL2" | bc)
echo $RES | tr '0123456789abc' 'gtaio luSnemf'

