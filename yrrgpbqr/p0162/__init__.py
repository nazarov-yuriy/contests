import unittest
from typing import List


# ToDo: log n solution
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        for i, num in enumerate(nums):
            left = nums[i - 1] if i - 1 >= 0 else -(2 ** 32)
            right = nums[i + 1] if i + 1 < len(nums) else -(2 ** 32)
            if left < num and right < num:
                return i
        return -1


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 2, 3, 1]
        out = 2
        self.assertEqual(Solution().findPeakElement(nums), out)
        nums = [1, 2, 1, 3, 5, 6, 4]
        out = 1
        self.assertEqual(Solution().findPeakElement(nums), out)
