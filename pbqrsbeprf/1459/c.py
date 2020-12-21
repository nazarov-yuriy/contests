from sys import stdin


def gcd(a, b):
    while b != 0:
        t = b
        b = a % b
        a = t
    return a


n, m = [int(x) for x in stdin.readline().split()]
a = [int(x) for x in stdin.readline().split()]
b = [int(x) for x in stdin.readline().split()]
sorted_a = sorted(set(a))
a0 = sorted_a[0]

a_minus_a0 = [x - a0 for x in sorted_a[1:]]

if a_minus_a0:
    res = gcd(a_minus_a0[0], a_minus_a0[0])
    for x in a_minus_a0[1:]:
        res = gcd(res, x)
else:
    res = None

for bj in b:
    if res is not None:
        print(gcd(a0 + bj, res))
    else:
        print(a0 + bj)
