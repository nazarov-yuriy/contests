import sys

sys.setrecursionlimit(3000)
cache = [0] * 3009


def fib(n):
    if (n == 1) or (n == 2):
        return 1
    if cache[n] != 0:
        return cache[n]
    cache[n] = fib(n - 1) + fib(n - 2)
    return cache[n]


(i, fi, j, fj, n) = [int(x) for x in raw_input().split(' ')]
if i == n:
    print fi
elif j == n:
    print fj
else:
    cai = fib(i + 1007)
    cbi = fib(i + 1006)
    caj = fib(j + 1007)
    cbj = fib(j + 1006)
    a = (fi * cbj - fj * cbi) / (cai * cbj - caj * cbi)
    b = (fi * caj - fj * cai) / (cbi * caj - cbj * cai)

    print fib(n + 1007) * a + fib(n + 1006) * b
