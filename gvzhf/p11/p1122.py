from sys import stdin


def field2num(s):
    res = 0
    for i in range(len(s)):
        if s[i] == 'B':
            res |= 1 << i
    return res

def diff2num(d, x, y, field_size=4):
    diff_extended = [
        [0 for _ in range(field_size + 2)] for _ in range(field_size + 2)
    ]
    for i, line in enumerate(d):
        for j, el in enumerate(line):
            diff_extended[i + x][j + y] = el

    res = 0
    for i in range(field_size):
        for j in range(field_size):
            if diff_extended[i + 1][j + 1] == 1:
                res |= 1 << (i * field_size + j)
    return res


field = ''.join(stdin.readline().strip() for _ in range(4))
diff = [[int(x) for x in stdin.readline().strip()] for _ in range(3)]

all_fields = range(2<<(4*4))
all_diffs = [
    diff2num(diff, x, y) for x in range(4) for y in range(4)
]

visited = {}
front = {
    field2num(field): None
}

front_num = 0
while front:
    # print(len(visited))
    for curr in front:
        visited[curr] = front[curr]
        if curr == 0 or curr == ((1<<16) - 1):
            print(front_num)
            # while curr != None:
            #     print("{0:016b}".format(curr))
            #     curr = visited[curr]
            exit(0)
    front_arr = list(front)
    front.clear()
    front_num += 1

    for curr in front_arr:
        for dn in all_diffs:
            new = curr ^ dn
            if new not in visited:
                front[new] = curr
print('Impossible')
