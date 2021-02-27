import unittest
from typing import List


class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        last = None
        max_num = nums[0]
        for i, num in enumerate(nums):
            if num < max_num:
                last = i
            max_num = max(max_num, num)
        first = None
        min_num = nums[-1]
        for i in range(len(nums) - 1, -1, -1):
            num = nums[i]
            if num > min_num:
                first = i
            min_num = min(min_num, num)
        if last is None:
            return 0
        else:
            return last - first + 1


class Test(unittest.TestCase):
    def test(self):
        nums = [2, 6, 4, 8, 10, 9, 15]
        out = 5
        self.assertEqual(Solution().findUnsortedSubarray(nums), out)
        nums = [1, 2, 3, 4]
        out = 0
        self.assertEqual(Solution().findUnsortedSubarray(nums), out)
        nums = [1]
        out = 0
        self.assertEqual(Solution().findUnsortedSubarray(nums), out)
