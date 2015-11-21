#!/usr/bin/python
n = int(raw_input())
s = sum( int(x) for x in raw_input().split(' ') )
if 1 == (((s-n)/2)%2):
    print 'Daenerys'
else:
    print 'Stannis'
