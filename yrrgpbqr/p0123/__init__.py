import unittest
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0

        minimum = prices[0]
        best_prevs = [0] * len(prices)
        best_prev = 0
        for i, price in enumerate(prices):
            minimum = min(minimum, price)
            best_prev = max(best_prev, price - minimum)
            best_prevs[i] = best_prev

        maximum = prices[-1]
        best_next = 0
        best = 0
        for i, price in reversed(list(enumerate(prices))):
            maximum = max(maximum, price)
            best_next = max(best_next, maximum - price)
            best = max(best, best_next + best_prevs[i])

        return best


class Test(unittest.TestCase):
    def test(self):
        prices = [3, 3, 5, 0, 0, 3, 1, 4]
        self.assertEqual(Solution().maxProfit(prices), 6)
        prices = [1, 2, 3, 4, 5]
        self.assertEqual(Solution().maxProfit(prices), 4)
        prices = [7, 6, 4, 3, 1]
        self.assertEqual(Solution().maxProfit(prices), 0)
        prices = [1]
        self.assertEqual(Solution().maxProfit(prices), 0)
