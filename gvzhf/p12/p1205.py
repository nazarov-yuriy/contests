from sys import stdin
from math import sqrt

v_walk, v_undergeound = [float(z) for z in stdin.readline().split()]

N = int(stdin.readline())

stations = [None]  # to place A
links = []
for _ in range(N):
    x, y = [float(z) for z in stdin.readline().split()]
    stations.append((x, y))

while True:
    f, t = [int(z) for z in stdin.readline().split()]
    if f == 0 and t == 0:
        break
    links.append((f, t))
    links.append((t, f))

A = tuple([float(z) for z in stdin.readline().split()])
B = tuple([float(z) for z in stdin.readline().split()])
stations[0] = B
stations.append(A)


# build graph
def distance(p1, p2):
    return sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)


durations = [
    [distance(stations[i], stations[j]) / v_walk for j in range(len(stations))] for i in range(len(stations))
]
for link in links:
    i, j = link[0], link[1]
    durations[i][j] = distance(stations[i], stations[j]) / v_undergeound

# Dijkstra
Q = set(range(len(stations)))
dist = [1e99 for _ in range(len(stations))]
prev = [None for _ in range(len(stations))]
dist[0] = 0  # Source/B

while Q:
    Q_list = list(Q)
    min_i = Q_list[0]
    min_d = dist[min_i]
    for i in Q_list:
        if dist[i] < min_d:
            min_d = dist[i]
            min_i = i
    Q.remove(min_i)

    for i in range(len(stations)):
        alt = dist[min_i] + durations[min_i][i]
        if alt < dist[i]:
            dist[i] = alt
            prev[i] = min_i

print(dist[-1])
i = len(stations) - 1
res = []
while True:
    i = prev[i]
    if i == 0:
        break
    res.append(i)

print(len(res), end=' ')
print(*res)
