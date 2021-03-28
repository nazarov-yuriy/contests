import unittest
from typing import List
import collections


class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        rows = len(matrix)
        if rows == 0:
            return []
        cols = len(matrix[0])
        if cols == 0:
            return []
        pacific = [[False] * len(row) for row in matrix]
        queue = collections.deque()
        for i in range(rows):
            pacific[i][0] = True
            queue.append((i, 0))
        for i in range(cols):
            pacific[0][i] = True
            queue.append((0, i))
        while len(queue) > 0:
            r, c = queue.popleft()
            h = matrix[r][c]
            for nr, nc in [(r, c - 1), (r, c + 1), (r - 1, c), (r + 1, c)]:
                if 0 <= nr < rows and 0 <= nc < cols and not pacific[nr][nc] and matrix[nr][nc] >= h:
                    pacific[nr][nc] = True
                    queue.append((nr, nc))
        atlantic = [[False] * len(row) for row in matrix]
        queue = collections.deque()
        for i in range(rows):
            atlantic[i][cols - 1] = True
            queue.append((i, cols - 1))
        for i in range(cols):
            atlantic[rows - 1][i] = True
            queue.append((rows - 1, i))
        while len(queue) > 0:
            r, c = queue.popleft()
            h = matrix[r][c]
            for nr, nc in [(r, c - 1), (r, c + 1), (r - 1, c), (r + 1, c)]:
                if 0 <= nr < rows and 0 <= nc < cols and not atlantic[nr][nc] and matrix[nr][nc] >= h:
                    atlantic[nr][nc] = True
                    queue.append((nr, nc))
        res = []
        for r in range(rows):
            for c in range(cols):
                if pacific[r][c] and atlantic[r][c]:
                    res.append([r, c])
        return res


class Test(unittest.TestCase):
    def test(self):
        heights = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
        out = [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]
        self.assertEqual(Solution().pacificAtlantic(heights), out)
