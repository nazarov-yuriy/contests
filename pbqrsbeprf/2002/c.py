from sys import stdin


def sq_dist(x1, y1, x2, y2):
    return (x1 - x2) ** 2 + (y1 - y2) ** 2


t = int(stdin.readline())
for _ in range(t):
    n = int(stdin.readline())
    coords = []
    for _ in range(n):
        a, b = map(int, stdin.readline().split())
        coords.append((a, b))
    xs, ys, xt, yt = map(int, stdin.readline().split())
    d = sq_dist(xt, yt, xs, ys)
    res = True
    for x, y in coords:
        if sq_dist(x, y, xt, yt) <= d:
            res = False
            break
    print("YES" if res else "NO")
