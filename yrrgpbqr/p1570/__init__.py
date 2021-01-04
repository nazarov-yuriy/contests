import unittest
from typing import List


class SparseVector:
    def __init__(self, nums: List[int]):
        self.values = {i: num for i, num in enumerate(nums) if num != 0}

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        res = 0
        for key in set(self.values) | set(vec.values):
            res += self.values.get(key, 0) * vec.values.get(key, 0)
        return res


class Test(unittest.TestCase):
    def test(self):
        nums1 = [1, 0, 0, 2, 3]
        nums2 = [0, 3, 0, 4, 0]
        v1 = SparseVector(nums1)
        v2 = SparseVector(nums2)
        self.assertEqual(v1.dotProduct(v2), 8)
        nums1 = [0, 1, 0, 0, 0]
        nums2 = [0, 0, 0, 0, 2]
        v1 = SparseVector(nums1)
        v2 = SparseVector(nums2)
        self.assertEqual(v1.dotProduct(v2), 0)
        nums1 = [0, 1, 0, 0, 2, 0, 0]
        nums2 = [1, 0, 0, 0, 3, 0, 4]
        v1 = SparseVector(nums1)
        v2 = SparseVector(nums2)
        self.assertEqual(v1.dotProduct(v2), 6)
