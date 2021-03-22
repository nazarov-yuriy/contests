import unittest
from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        INF = int(10 ** 9)
        res = [INF] * (amount + 1)
        res[0] = 0
        for i in range(1, amount + 1):
            local_res = INF
            for coin in coins:
                if i - coin >= 0:
                    local_res = min(local_res, res[i - coin] + 1)
            res[i] = local_res
        return res[amount] if res[amount] < INF else -1


class Test(unittest.TestCase):
    def test(self):
        coins = [1, 2, 5]
        amount = 11
        out = 3
        self.assertEqual(Solution().coinChange(coins, amount), out)
