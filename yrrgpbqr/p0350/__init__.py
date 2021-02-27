import unittest
from typing import List
from collections import Counter


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list((Counter(nums1) & Counter(nums2)).elements())


class Test(unittest.TestCase):
    def test(self):
        nums1 = [1, 2, 2, 1]
        nums2 = [2, 2]
        out = [2, 2]
        self.assertEqual(Solution().intersect(nums1, nums2), out)
