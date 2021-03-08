from sys import stdin

t = int(stdin.readline())
for _ in range(t):
    n, u, v = [int(x) for x in stdin.readline().split()]
    a = [int(x) for x in stdin.readline().split()]
    if min(a) == max(a):
        res = min(v + u, v + v)
    else:
        res = min(u, v)
        for ai, ai_plus_1 in zip(a[:-1], a[1:]):
            if abs(ai - ai_plus_1) > 1:
                res = 0
    print(res)
