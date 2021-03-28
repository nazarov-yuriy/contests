import unittest
from typing import List


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        first_sum = {0: -1}
        s = 0
        res = 0
        for i, num in enumerate(nums):
            if num:
                s += 1
            else:
                s -= 1
            if s not in first_sum:
                first_sum[s] = i
            res = max(res, i - first_sum[s])
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [0, 1]
        out = 2
        self.assertEqual(Solution().findMaxLength(nums), out)
        nums = [0, 1, 0]
        out = 2
        self.assertEqual(Solution().findMaxLength(nums), out)
        nums = [0, 1, 0, 1]
        out = 4
        self.assertEqual(Solution().findMaxLength(nums), out)
