from sys import stdin

q = int(stdin.readline())

for _ in range(q):
    s = stdin.readline().strip()
    t = stdin.readline().strip()
    p = stdin.readline().strip()
    char_counts = {}
    for c in p:
        char_counts[c] = char_counts.get(c, 0) + 1
    s_pos = 0
    t_pos = 0
    while t_pos < len(t):
        if s_pos < len(s) and s[s_pos] == t[t_pos]:
            s_pos += 1
            t_pos += 1
        elif char_counts.get(t[t_pos], 0) > 0:
            char_counts[t[t_pos]] -= 1
            t_pos += 1
        else:
            break
    if s_pos != len(s) or t_pos != len(t):
        print('NO')
    else:
        print('YES')
