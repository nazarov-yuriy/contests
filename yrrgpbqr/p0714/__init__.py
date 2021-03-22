import unittest
from typing import List


class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        res = 0
        s0, s1 = 0, -prices[0] - fee
        for price in prices:
            s0, s1 = max(s0, s1 + price), max(s1, s0 - price - fee)
            res = max(res, s0, s1)
        return res


class Test(unittest.TestCase):
    def test(self):
        prices = [1, 3, 2, 8, 4, 9]
        fee = 2
        out = 8
        self.assertEqual(Solution().maxProfit(prices, fee), out)
        prices = [1, 3, 7, 5, 10, 3]
        fee = 3
        out = 6
        self.assertEqual(Solution().maxProfit(prices, fee), out)
