import unittest
from typing import List


class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        sorted_inventory = sorted(inventory, reverse=True)
        res = 0
        for i, balls_count in enumerate(sorted_inventory):
            counts_count = i + 1
            if i == len(sorted_inventory) - 1:
                diff = balls_count
            else:
                diff = balls_count - sorted_inventory[i + 1]
            if orders >= counts_count * diff:
                res += ((balls_count * (balls_count + 1) // 2) - (
                            (balls_count - diff) * (balls_count - diff + 1) // 2)) * counts_count
                orders -= counts_count * diff
            else:
                diff = orders // counts_count
                res += ((balls_count * (balls_count + 1) // 2) - (
                            (balls_count - diff) * (balls_count - diff + 1) // 2)) * counts_count
                orders -= counts_count * diff
                res += (balls_count - diff) * orders
                break
        return res % (10 ** 9 + 7)


class Test(unittest.TestCase):
    def test(self):
        inventory = [2, 5]
        orders = 4
        self.assertEqual(Solution().maxProfit(inventory, orders), 14)
        inventory = [3, 5]
        orders = 6
        self.assertEqual(Solution().maxProfit(inventory, orders), 19)
        inventory = [2, 8, 4, 10, 6]
        orders = 20
        self.assertEqual(Solution().maxProfit(inventory, orders), 110)
        inventory = [1000000000]
        orders = 1000000000
        self.assertEqual(Solution().maxProfit(inventory, orders), 21)
