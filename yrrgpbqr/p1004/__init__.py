import unittest
from typing import List


class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        res = 0
        l, r = 0, 0
        while r < len(A):
            while r < len(A) and (A[r] == 1 or K > 0):
                if A[r] == 0:
                    K -= 1
                r += 1
            res = max(res, r - l)
            if A[l] == 0 and l != r:
                K += 1
            l += 1
            r = max(r, l)
        return res


class Test(unittest.TestCase):
    def test(self):
        A = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0]
        K = 2
        out = 6
        self.assertEqual(Solution().longestOnes(A, K), out)
        A = [0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1]
        K = 3
        out = 10
        self.assertEqual(Solution().longestOnes(A, K), out)
        A = [0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1]
        K = 0
        out = 4
        self.assertEqual(Solution().longestOnes(A, K), out)
