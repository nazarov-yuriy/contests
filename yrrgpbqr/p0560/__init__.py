import unittest
from typing import List
from collections import Counter


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        position_by_sum = Counter([0])
        sum = 0
        res = 0
        for i, num in enumerate(nums):
            sum += num
            res += position_by_sum[sum - k]
            position_by_sum[sum] += 1
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 1, 1]
        k = 2
        self.assertEqual(Solution().subarraySum(nums, k), 2)
        nums = [1, 2, 3]
        k = 3
        self.assertEqual(Solution().subarraySum(nums, k), 2)
