import unittest
from typing import List


class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        cache = [[None] * (len(stones) + 1) for _ in range(len(stones) + 1)]
        sums = [0] * (1 + len(stones))
        for i, val in enumerate(stones):
            sums[i + 1] = sums[i] + val

        def calc_score(l, r, turn):
            if r - l <= 1:
                return 0
            if cache[l][r] is None:
                left_score = calc_score(l + 1, r, turn + 1)
                right_score = calc_score(l, r - 1, turn + 1)
                if turn % 2 == 0:  # Alice
                    cache[l][r] = max(
                        left_score + sums[r] - sums[l + 1],
                        right_score + sums[r - 1] - sums[l],
                    )
                else:  # Bob
                    cache[l][r] = min(
                        left_score - (sums[r] - sums[l + 1]),
                        right_score - (sums[r - 1] - sums[l]),
                    )
            return cache[l][r]

        return calc_score(0, len(stones), 0)


class Test(unittest.TestCase):
    def test(self):
        stones = [5, 3, 1, 4, 2]
        self.assertEqual(Solution().stoneGameVII(stones), 6)
        stones = [7, 90, 5, 1, 100, 10, 10, 2]
        self.assertEqual(Solution().stoneGameVII(stones), 122)
