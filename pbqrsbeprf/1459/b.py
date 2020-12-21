from sys import stdin

n = int(stdin.readline())

if n % 2 == 0:
    res = (n // 2 + 1) ** 2
else:
    m = (n + 1) // 2
    res = m * (m + 1) * 2
print(res)
