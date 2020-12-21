from sys import stdin

t = int(stdin.readline())

for _ in range(t):
    n = int(stdin.readline())
    r = stdin.readline().rstrip()
    b = stdin.readline().rstrip()
    res = 0
    for ri, bi in zip(r, b):
        if ri > bi:
            res += 1
        elif ri < bi:
            res -= 1
    if 0 == res:
        print('EQUAL')
    elif res > 0:
        print('RED')
    else:
        print('BLUE')
