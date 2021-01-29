import unittest
from typing import List
import heapq


class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        INF = float("inf")
        rows = len(heights)
        cols = len(heights[0])
        pq = [(0, (0, 0))]  # effort, (r, c)
        seen = {}
        while len(pq) > 0:
            effort, (r, c) = heapq.heappop(pq)
            if (r, c) == (rows-1, cols-1):
                return effort
            for nr, nc in [(r, c-1), (r, c+1), (r-1, c), (r+1, c)]:
                if 0 <= nr < rows and 0 <= nc < cols:
                    new_effort = max(effort, abs(heights[nr][nc] - heights[r][c]))
                    if new_effort < seen.get((nr, nc), INF):
                        seen[(nr, nc)] = new_effort
                        heapq.heappush(pq, (new_effort, (nr, nc)))


class Test(unittest.TestCase):
    def test(self):
        heights = [[1, 2, 2], [3, 8, 2], [5, 3, 5]]
        out = 2
        self.assertEqual(Solution().minimumEffortPath(heights), out)
        heights = [[1, 2, 3], [3, 8, 4], [5, 3, 5]]
        out = 1
        self.assertEqual(Solution().minimumEffortPath(heights), out)
        heights = [[1, 2, 1, 1, 1], [1, 2, 1, 2, 1], [1, 2, 1, 2, 1], [1, 2, 1, 2, 1], [1, 1, 1, 2, 1]]
        out = 0
        self.assertEqual(Solution().minimumEffortPath(heights), out)
