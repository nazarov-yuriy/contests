import unittest
from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) != len(nums)


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 2, 3, 1]
        out = True
        self.assertEqual(Solution().containsDuplicate(nums), out)
        nums = [1, 2, 3, 4]
        out = False
        self.assertEqual(Solution().containsDuplicate(nums), out)
