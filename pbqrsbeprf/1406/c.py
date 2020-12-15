from sys import stdin
from copy import deepcopy
from collections import deque

t = int(stdin.readline())

for _ in range(t):
    n = int(stdin.readline())
    orig_edges = set()
    edges = {}
    for i in range(n - 1):
        a, b = [int(x) for x in stdin.readline().split()]
        orig_edges.add((a, b))
        edges.setdefault(a, set()).add(b)
        edges.setdefault(b, set()).add(a)

    traversal_order = {}
    pos = 0
    node = 1
    stack = deque()
    edges_copy = deepcopy(edges)
    while True:
        if edges_copy[node]:
            neighbor = next(iter(edges_copy[node]))
            edges_copy[node].remove(neighbor)
            edges_copy[neighbor].remove(node)
            stack.append(node)
            traversal_order[(node, neighbor)] = pos
            pos += 0.5
            node = neighbor
        else:
            if len(stack) == 0:
                break
            neighbor = stack.pop()
            pos += 0.5
            traversal_order[(node, neighbor)] = pos
            node = neighbor

    min_max_left = n
    min_max_left_nodes = []
    for node in edges:
        max_left = 0
        for neighbor in edges[node]:
            max_left = max(max_left, (traversal_order[(neighbor, node)] - traversal_order[(node, neighbor)] + n) % n)
        if max_left < min_max_left:
            min_max_left_nodes = [node]
            min_max_left = max_left
        elif max_left == min_max_left:
            min_max_left_nodes.append(node)

    node = min_max_left_nodes[0]
    neighbor = next(iter(edges[node] - set(min_max_left_nodes)))
    if len(min_max_left_nodes) == 1:
        if (node, neighbor) in orig_edges:
            print(node, neighbor)
            print(node, neighbor)
        else:
            print(neighbor, node)
            print(neighbor, node)
    else:
        if (node, neighbor) in orig_edges:
            print(node, neighbor)
        else:
            print(neighbor, node)
        print(min_max_left_nodes[1], neighbor)
