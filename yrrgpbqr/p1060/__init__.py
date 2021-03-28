import unittest
from typing import List


class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        missing_count = nums[-1] - nums[0] + 1 - len(nums)
        if k > missing_count:
            return nums[-1] + k - missing_count
        l, r = 0, len(nums)
        while r - l > 1:
            m = (l + r) // 2
            missing_count_m = nums[m] - nums[0] + 1 - (m + 1)
            if missing_count_m < k:
                l = m
            else:
                r = m
        missing_count_l = nums[l] - nums[0] + 1 - (l + 1)
        return nums[l] + k - missing_count_l


class Test(unittest.TestCase):
    def test(self):
        nums = [4, 7, 9, 10]
        k = 1
        out = 5
        self.assertEqual(Solution().missingElement(nums, k), out)
        nums = [4, 7, 9, 10]
        k = 3
        out = 8
        self.assertEqual(Solution().missingElement(nums, k), out)
        nums = [1,2,4]
        k = 3
        out = 6
        self.assertEqual(Solution().missingElement(nums, k), out)
