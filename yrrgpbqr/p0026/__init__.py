import unittest
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        l, r = 0, 0
        while r < len(nums):
            nums[l] = nums[r]
            while r < len(nums) and nums[r] == nums[l]:
                r += 1
            l += 1
        return l


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 1, 2]
        out_nums = [1, 2]
        self.assertEqual(nums[:Solution().removeDuplicates(nums)], out_nums)
        nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
        out_nums = [0, 1, 2, 3, 4]
        self.assertEqual(nums[:Solution().removeDuplicates(nums)], out_nums)
