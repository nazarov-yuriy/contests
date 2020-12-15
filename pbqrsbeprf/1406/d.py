from sys import stdin

n = int(stdin.readline())
a = [int(x) for x in stdin.readline().split()]
prev = a[0]
diff = [prev]
bsum = prev
for el in a[1:]:
    d = el - prev
    diff.append(d)
    if d > 0:
        bsum += d
    prev = el

print((bsum + 1) // 2)

q = int(stdin.readline())
for _ in range(q):
    l, r, w = [int(x) for x in stdin.readline().split()]
    if l == 1:
        bsum += w
        diff[l - 1] += w
    else:
        if diff[l - 1] > 0:
            bsum -= diff[l - 1]
        diff[l - 1] += w
        if diff[l - 1] > 0:
            bsum += diff[l - 1]
    if r < n:
        if diff[r] > 0:
            bsum -= diff[r]
        diff[r] -= w
        if diff[r] > 0:
            bsum += diff[r]
    print((bsum + 1) // 2)
