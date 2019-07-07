from sys import stdin

M = int(stdin.readline())

segments = []
while True:
    l, r = [int(x) for x in stdin.readline().split()]
    if l == 0 and r == 0:
        break
    # l = max(0, l)
    # r = min(M, r)
    # if l >= r:
    #     continue
    segments.append((l, r))

segments.sort()
segments.append((M, M))  # dummy segment to unify handling last segment

found_up_to = 0
max_r = 0
max_r_id = 0
res = []

for i, segment in enumerate(segments):
    if segment[0] > found_up_to:
        res.append(segments[max_r_id])
        found_up_to = max_r
        if found_up_to >= M:
            break
        if segment[0] > found_up_to:
            break

    if segment[1] > max_r:
        max_r = segment[1]
        max_r_id = i

if found_up_to >= M:
    print(len(res))
    for segment in res:
        print(segment[0], segment[1])
else:
    print('No solution')
