import unittest
from typing import List


class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        cache = [None] * (len(stoneValue) + 1)

        def get_score(l):
            if l >= len(stoneValue):
                return 0
            if cache[l] is None:
                cache[l] = max(
                    sum(stoneValue[l:l + 1]) - get_score(l + 1),
                    sum(stoneValue[l:l + 2]) - get_score(l + 2),
                    sum(stoneValue[l:l + 3]) - get_score(l + 3),
                )
            return cache[l]

        score = get_score(0)
        if score == 0:
            return "Tie"
        elif score > 0:
            return "Alice"
        else:
            return "Bob"


class Test(unittest.TestCase):
    def test(self):
        values = [1, 2, 3, 7]
        self.assertEqual(Solution().stoneGameIII(values), "Bob")
        values = [1, 2, 3, -9]
        self.assertEqual(Solution().stoneGameIII(values), "Alice")
