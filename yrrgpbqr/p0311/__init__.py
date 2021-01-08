import unittest
from typing import List


class Solution:
    def multiply(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        sparse_A = [
            {k: v for k, v in enumerate(row) if v != 0}
            for row in A
        ]
        sparse_BT = [
            {k: v for k, v in enumerate(row) if v != 0}
            for row in zip(*B)
        ]
        res = [[0]*len(sparse_BT) for _ in range(len(sparse_A))]
        for i, sparse_row_A in enumerate(sparse_A):
            for j, sparse_row_BT in enumerate(sparse_BT):
                for k in set(sparse_row_A).intersection(set(sparse_row_BT)):
                    res[i][j] += sparse_row_A[k] * sparse_row_BT[k]
        return res


class Test(unittest.TestCase):
    def test(self):
        A = [
            [1, 0, 0],
            [-1, 0, 3],
        ]
        B = [
            [7, 0, 1],
            [0, 0, 0],
            [0, 0, 1],
        ]
        AB = [
            [7, 0 ,1],
            [-7, 0, 2],
        ]
        self.assertEqual(Solution().multiply(A, B), AB)
