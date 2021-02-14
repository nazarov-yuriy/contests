import unittest
from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        s = 0
        min_s = 10 ** 9
        min_index = -1
        for i, (g, c) in enumerate(zip(gas, cost)):
            d = g - c
            s += d
            if s < min_s:
                min_s = s
                min_index = i
        if s < 0:
            return -1
        return (min_index + 1) % len(gas)


class Test(unittest.TestCase):
    def test(self):
        gas = [1, 2, 3, 4, 5]
        cost = [3, 4, 5, 1, 2]
        out = 3
        self.assertEqual(Solution().canCompleteCircuit(gas, cost), out)
        gas = [2, 3, 4]
        cost = [3, 4, 3]
        out = -1
        self.assertEqual(Solution().canCompleteCircuit(gas, cost), out)
