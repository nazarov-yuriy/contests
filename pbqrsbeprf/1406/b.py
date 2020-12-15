from sys import stdin
from functools import reduce

t = int(stdin.readline())

for _ in range(t):
    n = int(stdin.readline())
    a = [int(y) for y in stdin.readline().split()]
    sorted_a = sorted(a)
    print(max(
        reduce(lambda x, y: x * y, sorted_a[-5:]),
        max(
            reduce(lambda x, y: x * y, sorted_a[:2] + sorted_a[-3:]),
            reduce(lambda x, y: x * y, sorted_a[:4] + sorted_a[-1:])
        )
    ))
