#!/usr/bin/python
a = raw_input()
b = raw_input()
c = raw_input()

m = eval(a+'+'+b+'+'+c)
for o1 in ['+', '-', '*']:
    for o2 in ['+', '-', '*']:
        m = min(m, eval(a+o1+b+o2+c))
        m = min(m, eval(a+o1+c+o2+b))
        m = min(m, eval(b+o1+a+o2+c))
        m = min(m, eval(b+o1+c+o2+a))
        m = min(m, eval(c+o1+b+o2+a))
        m = min(m, eval(c+o1+a+o2+b))

print m
