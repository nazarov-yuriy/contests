import unittest
from typing import List


class Solution:
    def lowerBound(self, nums, target):
        l, r = -1, len(nums)
        while r - l > 1:
            m = (l + r) // 2
            if nums[m] < target:
                l = m
            else:
                r = m
        return r

    def upperBound(self, nums, target):
        l, r = -1, len(nums)
        while r - l > 1:
            m = (l + r) // 2
            if nums[m] <= target:
                l = m
            else:
                r = m
        return l

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        lower = self.lowerBound(nums, target)
        upper = self.upperBound(nums, target)
        if lower == len(nums) or upper == -1:
            return [-1, -1]
        elif nums[lower] != target or nums[upper] != target:
            return [-1, -1]
        else:
            return [lower, upper]


class Test(unittest.TestCase):
    def test(self):
        nums = [5, 7, 7, 8, 8, 10]
        target = 8
        self.assertEqual(Solution().searchRange(nums, target), [3, 4])
        nums = [5,7,7,8,8,10]
        target = 6
        self.assertEqual(Solution().searchRange(nums, target), [-1, -1])
        nums = []
        target = 0
        self.assertEqual(Solution().searchRange(nums, target), [-1, -1])
