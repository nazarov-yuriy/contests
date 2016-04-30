#!/usr/bin/python
n = int(raw_input())

has_3 = False
has_4 = False
summ  = 0
for i in range(n):
    a = int(raw_input())
    if a == 3:
        has_3 = True
    if a == 4:
        has_4 = True
    summ += a

if has_3:
    print "None"
elif not has_4:
    print "Named"
elif summ * 10 >= 45 * n:
    print "High"
else:
    print "Common"
