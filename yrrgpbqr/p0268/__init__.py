import unittest
from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        return n * (n + 1) // 2 - sum(nums)


class Test(unittest.TestCase):
    def test(self):
        nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]
        out = 8
        self.assertEqual(Solution().missingNumber(nums), out)
        nums = [0]
        out = 1
        self.assertEqual(Solution().missingNumber(nums), out)
