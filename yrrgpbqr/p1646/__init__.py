import unittest
from typing import List


class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        nums = [0] * (n + 1)
        nums[0] = 0
        if 1 < len(nums):
            nums[1] = 1
        for j in range(2, len(nums)):  # j == 2*i or 2*i+1
            if j % 2 == 0:
                nums[j] = nums[j//2]
            else:
                nums[j] = nums[j//2] + nums[j//2+1]
        return max(nums)


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().getMaximumGenerated(0), 0)
        self.assertEqual(Solution().getMaximumGenerated(1), 1)
        self.assertEqual(Solution().getMaximumGenerated(2), 1)
        self.assertEqual(Solution().getMaximumGenerated(3), 2)
        self.assertEqual(Solution().getMaximumGenerated(7), 3)
