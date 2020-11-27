import unittest
from typing import List
from collections import deque


class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        depth = [1] * n
        edges_dict = {}
        for a, b in edges:
            edges_dict.setdefault(a, set()).add(b)
            edges_dict.setdefault(b, set()).add(a)
        q = deque()
        for i in range(n):
            if len(edges_dict.get(i, set())) == 1:
                q.append(i)
        while len(q) > 0:
            if len(edges_dict) == 2:
                break
            i = q.popleft()
            if len(edges_dict.get(i, set())):
                ne = next(iter(edges_dict[i]))
                edges_dict[ne].remove(i)
                depth[ne] = max(depth[ne], depth[i] + 1)
                if len(edges_dict[ne]) == 1:
                    q.append(ne)
            del edges_dict[i]
        max_depth = max(depth)
        return [i for i in range(n) if depth[i] == max_depth]


class Test(unittest.TestCase):
    def test(self):
        n = 4
        edges = [[1, 0], [1, 2], [1, 3]]
        self.assertEqual(
            [1],
            Solution().findMinHeightTrees(n, edges)
        )
        n = 6
        edges = [[3, 0], [3, 1], [3, 2], [3, 4], [5, 4]]
        self.assertEqual(
            [3, 4],
            Solution().findMinHeightTrees(n, edges)
        )
        n = 1
        edges = []
        self.assertEqual(
            [0],
            Solution().findMinHeightTrees(n, edges)
        )
        n = 2
        edges = [[0, 1]]
        self.assertEqual(
            [0, 1],
            Solution().findMinHeightTrees(n, edges)
        )
