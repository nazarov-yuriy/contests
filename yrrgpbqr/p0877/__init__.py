import unittest
from typing import List


class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        cache = [[None] * (len(piles) + 1) for _ in range(len(piles) + 1)]

        def get_score(l, r, turn):
            if l == r:
                return 0
            if cache[l][r] is None:
                left_score = get_score(l + 1, r, turn + 1)
                right_score = get_score(l, r - 1, turn + 1)
                if turn % 2 == 0:  # Alex
                    cache[l][r] = max(
                        left_score + piles[l],
                        right_score + piles[r - 1]
                    )
                else:  # Lee
                    cache[l][r] = min(
                        left_score - piles[l],
                        right_score - piles[r - 1]
                    )
            return cache[l][r]

        return get_score(0, len(piles), 0) > 0


class Test(unittest.TestCase):
    def test(self):
        piles = [5, 3, 4, 5]
        self.assertEqual(Solution().stoneGame(piles), True)
