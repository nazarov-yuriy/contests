import unittest
from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        if len(nums2) == 0:
            return
        # move to tail
        l, r = len(nums1) - 1 - len(nums2), len(nums1) - 1
        while l >= 0:
            nums1[r] = nums1[l]
            l -= 1
            r -= 1
        pos1 = len(nums2)
        pos2 = 0
        pos = 0
        while pos1 < len(nums1) and pos2 < len(nums2):
            num1 = nums1[pos1]
            num2 = nums2[pos2]
            if num1 <= num2:
                nums1[pos] = num1
                pos1 += 1
            else:
                nums1[pos] = num2
                pos2 += 1
            pos += 1
        while pos2 < len(nums2):
            num2 = nums2[pos2]
            nums1[pos] = num2
            pos2 += 1
            pos += 1


class Test(unittest.TestCase):
    def test(self):
        nums1 = [1, 2, 3, 0, 0, 0]
        m = 3
        nums2 = [2, 5, 6]
        n = 3
        Solution().merge(nums1, m, nums2, n)
        self.assertEqual(nums1, [1, 2, 2, 3, 5, 6])
        nums1 = [0, 0, 0, 0, 0, 0]
        m = 0
        nums2 = [1, 2, 2, 3, 5, 6]
        n = 6
        Solution().merge(nums1, m, nums2, n)
        self.assertEqual(nums1, [1, 2, 2, 3, 5, 6])
        nums1 = [1, 2, 2, 3, 5, 6]
        m = 6
        nums2 = []
        n = 0
        Solution().merge(nums1, m, nums2, n)
        self.assertEqual(nums1, [1, 2, 2, 3, 5, 6])
