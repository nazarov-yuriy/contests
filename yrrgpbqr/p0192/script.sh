#!/bin/bash
tr -s ' ' '\n' < words.txt | sort | uniq -c | sort -rn | sed 's~^ *\(.*\) \(.*\)~\2 \1~'