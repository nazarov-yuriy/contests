import unittest
from typing import List
import collections


class Node:
    def __init__(self):
        self.parent = self
        self.size = 1


class DisjointSet:
    def __init__(self, capacity):
        self.nodes = [Node() for _ in range(capacity)]

    def find(self, x):
        root = self.nodes[x]
        while root.parent != root:
            root = root.parent
        node = self.nodes[x]
        while node.parent != root:
            node, node.parent = node.parent, root
        return root

    def union(self, x, y):
        node_x = self.find(x)
        node_y = self.find(y)
        if node_x == node_y:
            return False
        if node_x.size < node_y.size:
            node_x, node_y = node_y, node_x
        node_y.parent = node_x
        node_x.size = node_x.size + node_y.size
        return True


class Solution:
    LAND = 1

    def numIslands(self, grid: List[List[str]]) -> int:
        seen = [[False] * len(row) for row in grid]
        res = 0
        rows = len(grid)
        cols = len(grid[0])
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == self.LAND and not seen[r][c]:
                    res += 1
                    queue = collections.deque([(r, c)])
                    seen[r][c] = True
                    while len(queue) > 0:
                        cur_r, cur_c = queue.popleft()
                        for dr, dc in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
                            new_r, new_c = cur_r + dr, cur_c + dc
                            if 0 <= new_r < rows and 0 <= new_c < cols and grid[new_r][new_c] == self.LAND and not \
                                    seen[new_r][new_c]:
                                queue.append((new_r, new_c))
                                seen[new_r][new_c] = True
        return res

    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        # # slow
        # grid = [[0] * n for _ in range(n)]
        # res = []
        # for r, c in positions:
        #     grid[r][c] = self.LAND
        #     res.append(self.numIslands(grid))
        # return res
        rows = m
        cols = n
        grid = [[0] * cols for _ in range(rows)]
        disjoint_set = DisjointSet(rows * cols)
        res = []
        islands = 0
        for r, c in positions:
            if grid[r][c] == 0:
                grid[r][c] = self.LAND
                islands += 1
                for dr, dc in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == self.LAND:
                        if disjoint_set.union(r * cols + c, nr * cols + nc):
                            islands -= 1
            res.append(islands)
        return res


class Test(unittest.TestCase):
    def test(self):
        m = 3
        n = 3
        positions = [[0, 0], [0, 1], [1, 2], [2, 1]]
        out = [1, 1, 2, 3]
        self.assertEqual(Solution().numIslands2(m, n, positions), out)
        m = 8
        n = 4
        positions = [[0, 0], [7, 1], [6, 1], [3, 3], [4, 1]]
        out = [1, 2, 2, 3, 4]
        self.assertEqual(Solution().numIslands2(m, n, positions), out)
