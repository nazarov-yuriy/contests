import unittest
from typing import List


class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        sums = [0] * (len(stoneValue) + 1)
        for i, val in enumerate(stoneValue):
            sums[i + 1] = sums[i] + val
        cache_val = [[None] * (len(stoneValue) + 1) for _ in range(len(stoneValue) + 1)]

        def get_score(l, r):
            if r - l == 1:
                return 0
            if cache_val[l][r] is None:
                res = 0
                sl = sums[l]
                sr = sums[r]
                for i in range(l + 1, r):
                    si = sums[i]
                    score_left = si - sl
                    score_right = sr - si
                    if score_left == score_right:
                        next_left = cache_val[l][i] or get_score(l, i)
                        next_right = cache_val[i][r] or get_score(i, r)
                        if score_left + next_left > score_right + next_right:
                            score = score_left + next_left
                        else:
                            score = score_right + next_right
                    elif score_left > score_right:
                        next_right = cache_val[i][r] or get_score(i, r)
                        score = score_right + next_right
                    else:
                        next_left = cache_val[l][i] or get_score(l, i)
                        score = score_left + next_left
                    res = max(res, score)
                cache_val[l][r] = res
            return cache_val[l][r]

        return get_score(0, len(stoneValue))


class Test(unittest.TestCase):
    def test(self):
        stoneValue = [6, 2, 3, 4, 5, 5]
        self.assertEqual(Solution().stoneGameV(stoneValue), 18)

        stoneValue = [7, 7, 7, 7, 7, 7, 7]
        self.assertEqual(Solution().stoneGameV(stoneValue), 28)

        stoneValue = [4]
        self.assertEqual(Solution().stoneGameV(stoneValue), 0)

        stoneValue = [
            39994, 3, 4, 10000, 10000, 10000, 10000, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1000000
        ]
        self.assertEqual(Solution().stoneGameV(stoneValue), 150003)
