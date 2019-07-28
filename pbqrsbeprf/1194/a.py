from sys import stdin

T = int(stdin.readline())

for _ in range(T):
    n, x = [int(y) for y in stdin.readline().split()]
    print(2 * x)