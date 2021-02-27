import unittest
from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 0:
            return
        l, r = 0, 0
        while r < len(nums):
            while r < len(nums) and nums[r] == 0:
                r += 1
            if r < len(nums):
                nums[l] = nums[r]
                l += 1
                r += 1
        while l < len(nums):
            nums[l] = 0
            l += 1



class Test(unittest.TestCase):
    def test(self):
        nums = [0, 1, 0, 3, 12]
        out = [1, 3, 12, 0, 0]
        Solution().moveZeroes(nums)
        self.assertEqual(nums, out)
