import unittest
from typing import List
from collections import Counter


class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        component = [None] * len(nums)
        for i, num in enumerate(nums):
            c = i
            while component[c] is None:
                component[c] = i
                c = nums[c]
        return max(Counter(component).values())


class Test(unittest.TestCase):
    def test(self):
        nums = [5, 4, 0, 3, 1, 6, 2]
        self.assertEqual(
            4,
            Solution().arrayNesting(nums)
        )
