import unittest
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(max(0, y - x) for x, y in zip(prices[:-1], prices[1:]))

class Test(unittest.TestCase):
    def test(self):
        prices = [7,1,5,3,6,4]
        self.assertEquals(Solution().maxProfit(prices), 7)
        prices = [1,2,3,4,5]
        self.assertEquals(Solution().maxProfit(prices), 4)
        prices = [7,6,4,3,1]
        self.assertEquals(Solution().maxProfit(prices), 0)
