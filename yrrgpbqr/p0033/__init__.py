import unittest
from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while r - l > 1:
            m = (l + r) // 2
            if nums[l] < nums[m]:
                # l-m incr
                if nums[l] <= target <= nums[m]:
                    r = m
                else:
                    l = m + 1
            else:
                # m-r incr
                if nums[m] <= target <= nums[r]:
                    l = m
                else:
                    r = m - 1
        if nums[l] == target:
            return l
        if nums[r] == target:
            return r
        return -1


class Test(unittest.TestCase):
    def test(self):
        # nums = [4, 5, 6, 7, 0, 1, 2]
        # target = 0
        # out = 4
        # self.assertEqual(Solution().search(nums, target), out)
        # nums = [4, 5, 6, 7, 0, 1, 2]
        # target = 3
        # out = -1
        # self.assertEqual(Solution().search(nums, target), out)
        # nums = [1]
        # target = 0
        # out = -1
        # self.assertEqual(Solution().search(nums, target), out)
        nums = [1, 3, 5]
        target = 3
        out = 1
        self.assertEqual(Solution().search(nums, target), out)
