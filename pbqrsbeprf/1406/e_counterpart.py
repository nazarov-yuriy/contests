# time python3 e.py < /tmp/fifo | python3 e_counterpart.py > /tmp/fifo
from sys import stdin, stdout, stderr
from random import random

n = 100000
x = int(random() * n) + 1

nums = set(range(1, n+1))

print(n)
stdout.flush()
line = stdin.readline()
requests_left = 10000
while line:
    assert requests_left >= 0
    requests_left -= 1
    action, a = line[0], int(line[2:])
    if 'A' == action:
        res = 0
        for i in range(a, n+1, a):
            if i in nums:
                res += 1
        print(res)
        stdout.flush()
    elif 'B' == action:
        res = 0
        for i in range(a, n + 1, a):
            if i in nums:
                res += 1
                if i != x:
                    nums.remove(i)
        print(res)
        stdout.flush()
    elif 'C' == action:
        if x != a:
            print(n, x, file=stderr)
        assert x == a
        break
    else:
        assert False
    line = stdin.readline()
