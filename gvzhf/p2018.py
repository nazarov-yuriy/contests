#!/usr/bin/python
import collections
arr = raw_input().split(' ')
n = int(arr[0])
a = int(arr[1])
b = int(arr[2])

qa = collections.deque( [0 for i in range(a)], a )
qb = collections.deque( [0 for i in range(b)], b )
qa.appendleft(1)
qb.appendleft(1)
sa = 1
sb = 1
for i in range(1,n):
    lasta = qa[-1]
    lastb = qb[-1]
    qa.appendleft(sb)
    qb.appendleft(sa)
    (sa, sb) = ((sa+sb-lasta+1000000007)%1000000007, (sb+sa-lastb+1000000007)%1000000007)

print (sa+sb)%1000000007
