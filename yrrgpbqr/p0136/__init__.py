import unittest
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            res ^= num
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [2, 2, 1]
        out = 1
        self.assertEqual(Solution().singleNumber(nums), out)
