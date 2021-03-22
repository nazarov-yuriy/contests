import unittest
from typing import List
import heapq


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        front = []
        seen = [[False] * len(row) for row in matrix]
        seen[0][0] = True
        heapq.heappush(front, (matrix[0][0], 0, 0))
        while k > 1:
            val, r, c = heapq.heappop(front)
            k -= 1
            for nr, nc in [(r, c + 1), (r + 1, c), (r + 1, c + 1)]:
                if nr < n and nc < n and not seen[nr][nc]:
                    seen[nr][nc] = True
                    heapq.heappush(front, (matrix[nr][nc], nr, nc))
        return heapq.heappop(front)[0]


class Test(unittest.TestCase):
    def test(self):
        matrix = [[1, 5, 9], [10, 11, 13], [12, 13, 15]]
        k = 8
        out = 13
        self.assertEqual(Solution().kthSmallest(matrix, k), out)
        matrix = [[-5]]
        k = 1
        out = -5
        self.assertEqual(Solution().kthSmallest(matrix, k), out)
