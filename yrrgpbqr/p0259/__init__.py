import unittest
from typing import List


class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        sorted_nums = sorted(nums)
        res = 0
        for p1, num1 in enumerate(sorted_nums):
            p3 = len(sorted_nums) - 1
            for p2 in range(p1+1, len(sorted_nums)):
                num2 = sorted_nums[p2]
                while p3 > p2 and num1 + num2 + sorted_nums[p3] >= target:
                    p3 -= 1
                if p3 > p2:
                    res += p3 - p2
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [-2, 0, 1, 3]
        target = 2
        out = 2
        self.assertEqual(Solution().threeSumSmaller(nums, target), out)
