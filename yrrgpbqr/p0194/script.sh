#!/bin/bash
i=1; for col in `head -n1 file.txt`; do cut -d' ' -f$i < file.txt | tr '\n' ' ' | sed 's~ $~\n~'; i=$(( $i + 1 )); done
