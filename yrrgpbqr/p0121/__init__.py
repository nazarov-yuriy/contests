import unittest
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0
        minimum = prices[0]
        max_profit = 0
        for price in prices:
            minimum = min(minimum, price)
            max_profit = max(max_profit, price - minimum)
        return max_profit

class Test(unittest.TestCase):
    def test(self):
        prices = [7,1,5,3,6,4]
        self.assertEquals(Solution().maxProfit(prices), 5)
        prices = [7,6,4,3,1]
        self.assertEquals(Solution().maxProfit(prices), 0)
