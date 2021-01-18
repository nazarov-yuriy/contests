import unittest
from typing import List
import collections


class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums_counts = collections.Counter(nums)
        res = 0
        for num in nums:
            complementary = k - num
            if num != complementary:
                if nums_counts[num] >= 1 and nums_counts[complementary] >= 1:
                    res += 1
                    nums_counts[num] -= 1
                    nums_counts[complementary] -= 1
            else:
                if nums_counts[num] >= 2:
                    res += 1
                    nums_counts[num] -= 2
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 2, 3, 4]
        k = 5
        self.assertEqual(Solution().maxOperations(nums, k), 2)
        nums = [3, 1, 3, 4, 3]
        k = 6
        self.assertEqual(Solution().maxOperations(nums, k), 1)
