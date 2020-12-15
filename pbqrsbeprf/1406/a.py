from collections import Counter
from sys import stdin

t = int(stdin.readline())

for _ in range(t):
    n = int(stdin.readline())
    a = [int(y) for y in stdin.readline().split()]
    counts = Counter(a)
    max_sequential = 0
    max_two_sequential = 0
    min_sequential_count = 2
    for i in range(len(a)):
        min_sequential_count = min(min_sequential_count, counts[i])
        if min_sequential_count >= 2:
            max_two_sequential = i + 1
        if min_sequential_count >= 1:
            max_sequential = i + 1
        else:
            break
    print(max_sequential + max_two_sequential)
