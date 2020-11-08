import unittest
from typing import List


class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        sums = [0]  # 0 - sum before
        s = 0
        for num in A:
            s += num
            sums.append(s)
        best_l = [0] * (len(A) + 1)
        best_m = [0] * (len(A) + 1)
        best = 0
        for i, num in enumerate(A):
            if i + 1 >= L:
                sum_l = sums[i + 1] - sums[i + 1 - L]
                best_l[i + 1] = max(sum_l, best_l[i])
            if i + 1 >= M:
                sum_m = sums[i + 1] - sums[i + 1 - M]
                best_m[i + 1] = max(sum_m, best_m[i])
            if i + 1 >= M + L:
                best = max(
                    best, max(
                        sum_l + best_m[i + 1 - L],
                        sum_m + best_l[i + 1 - M]
                    )
                )
        return best


class Test(unittest.TestCase):
    def test(self):
        A = [1, 2]
        L = 1
        M = 1
        self.assertEqual(Solution().maxSumTwoNoOverlap(A, L, M), 3)
        A = [0, 6, 5, 2, 2, 5, 1, 9, 4]
        L = 1
        M = 2
        self.assertEqual(Solution().maxSumTwoNoOverlap(A, L, M), 20)
        A = [3, 8, 1, 3, 2, 1, 8, 9, 0]
        L = 3
        M = 2
        self.assertEqual(Solution().maxSumTwoNoOverlap(A, L, M), 29)
        A = [2, 1, 5, 6, 0, 9, 5, 0, 3, 8]
        L = 4
        M = 3
        self.assertEqual(Solution().maxSumTwoNoOverlap(A, L, M), 31)
