#!/usr/bin/env python
from sys import stdin

c2n = {'i': 1, 'j': 1, 'a': 2, 'b': 2, 'c': 2, 'd': 3, 'e': 3, 'f': 3, 'g': 4, 'h': 4, 'k': 5, 'l': 5,
       'm': 6, 'n': 6, 'p': 7, 'r': 7, 's': 7, 't': 8, 'u': 8, 'v': 8, 'w': 9, 'x': 9, 'y': 9, 'o': 0, 'q': 0, 'z': 0}
inf = 1000000
s = stdin.readline().rstrip()
while s != "-1":
    d = {}
    n = int(stdin.readline())
    for i in range(n):
        w = stdin.readline().rstrip()
        wn = ''.join([str(c2n[c]) for c in w])
        d[wn] = w
    lens = [inf for _ in range(200)] + [0]  # lens[-1] = 0
    words = ['' for _ in range(200)]
    for pos in range(len(s)):
        if lens[pos - 1] < inf:
            for wn in d:
                if lens[pos - 1 + len(wn)] > lens[pos - 1] + 1 and s[pos:].startswith(wn):
                    lens[pos - 1 + len(wn)] = lens[pos - 1] + 1
                    words[pos - 1 + len(wn)] = d[wn]
    if lens[len(s) - 1] == inf:
        print "No solution."
    else:
        res = []
        pos = len(s) - 1
        while pos >= 0:
            res.append(words[pos])
            pos -= len(words[pos])
        print ' '.join(reversed(res))

    s = stdin.readline().rstrip()
