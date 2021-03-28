import unittest
from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        prev_sum = 0
        for i, num in enumerate(nums):
            if prev_sum == total - num - prev_sum:
                return i
            prev_sum += num
        return -1


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 7, 3, 6, 5, 6]
        out = 3
        self.assertEqual(Solution().pivotIndex(nums), out)
        nums = [1, 2, 3]
        out = -1
        self.assertEqual(Solution().pivotIndex(nums), out)
        nums = [2, 1, -1]
        out = 0
        self.assertEqual(Solution().pivotIndex(nums), out)
