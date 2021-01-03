import unittest
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return sorted(nums, reverse=True)[k - 1]  # ToDo: use quickselect algorithm


class Test(unittest.TestCase):
    def test(self):
        nums = [3, 2, 1, 5, 6, 4]
        k = 2
        self.assertEqual(Solution().findKthLargest(nums, k), 5)
        nums = [3, 2, 3, 1, 2, 4, 5, 5, 6]
        k = 4
        self.assertEqual(Solution().findKthLargest(nums, k), 4)
