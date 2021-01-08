import unittest
from typing import List


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        left = set(range(n))
        colors = [None] * n

        def paint(node, color):
            colors[node] = color
            left.remove(node)
            res = True
            for neighbor in graph[node]:
                if colors[neighbor] is None:
                    res = res and paint(neighbor, 1 - color)
                elif colors[neighbor] == color:
                    return False
            return res

        while len(left) > 0:
            node = next(iter(left))
            if not paint(node, 0):
                return False
        return True


class Test(unittest.TestCase):
    def test(self):
        # graph = [[1, 3], [0, 2], [1, 3], [0, 2]]
        # self.assertEqual(Solution().isBipartite(graph), True)
        # graph = [[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]]
        # self.assertEqual(Solution().isBipartite(graph), False)
        graph = [
            [2,3,5,6,7,8,9],[2,3,4,5,6,7,8,9],[0,1,3,4,5,6,7,8,9],[0,1,2,4,5,6,7,8,9],[1,2,3,6,9],
            [0,1,2,3,7,8,9],[0,1,2,3,4,7,8,9],[0,1,2,3,5,6,8,9],[0,1,2,3,5,6,7],[0,1,2,3,4,5,6,7]
        ]
        self.assertEqual(Solution().isBipartite(graph), False)
