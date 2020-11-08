import unittest
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i, num in enumerate(nums):
            if target - num in seen:
                return [seen[target - num], i]
            seen[num] = i

class Test(unittest.TestCase):
    def test(self):
        nums = [2, 7, 11, 15]
        target = 9
        self.assertEqual(Solution().twoSum(nums, target), [0, 1])
        nums = [3, 3]
        target = 6
        self.assertEqual(Solution().twoSum(nums, target), [0, 1])
