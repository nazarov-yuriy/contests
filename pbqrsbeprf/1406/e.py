from sys import stdin, stdout
import time

n = int(stdin.readline())
candidates = range(2, n + 1)
is_prime = [1] * (n + 1)
removed = [None] * (n + 1)
primes = []

st = time.time()
for d in candidates:
    if is_prime[d]:
        primes.append(d)
        currently_removed = 0
        for i in range(d, n + 1, d):
            currently_removed += is_prime[i]
            is_prime[i] = 0
        removed[d] = currently_removed
en = time.time()
# print(en - st, file=stderr)
# print(primes, file=stderr)
# print(removed[:10], file=stderr)
# print(is_prime[:10], file=stderr)
# print(len(primes), file=stderr)

total_removed = 0
check_period = 100
candidates = set()
for i, prime in enumerate(primes):
    print(f"B {prime}")
    stdout.flush()
    to_remove = int(stdin.readline())
    total_removed += to_remove
    if i % check_period == check_period - 1 or i == len(primes) - 1:
        print(f"A 1")
        stdout.flush()
        res_after = int(stdin.readline())
        # print(n - total_removed, res_after, removed[prime], file=stderr)
        if n - total_removed != res_after:
            candidates |= set(primes[max(i-check_period+1, 0):i+1])
            total_removed = n - res_after
    else:
        # print(n - total_removed, '-', removed[prime], file=stderr)
        pass
# print(candidates, file=stderr)
# print(len(candidates), file=stderr)
for candidate in list(candidates):
    print(f"A {candidate}")
    stdout.flush()
    res = int(stdin.readline())
    if res == 0:
        candidates.remove(candidate)
# print(candidates, file=stderr)

multipliers = []
for candidate in list(candidates):
    res = 1
    candidate_pow = candidate
    while res and candidate * candidate_pow <= n:
        print(f"A {candidate * candidate_pow}")
        stdout.flush()
        res = int(stdin.readline())
        if res == 1:
            candidate_pow *= candidate
    multipliers.append(candidate_pow)
# print(multipliers, file=stderr)
res = 1
for multiplier in multipliers:
    res *= multiplier
print(f"C {res}")
# print(f"C {res}", file=stderr)
stdout.flush()
