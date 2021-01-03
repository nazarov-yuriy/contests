import unittest
from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = []
        # prefix product
        product = 1
        for num in nums:
            res.append(product)
            product *= num
        # suffix product
        product = 1
        for i, num in enumerate(reversed(nums)):
            res[-1-i] *= product
            product *= num
        return res


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            Solution().productExceptSelf([1, 2, 3, 4]),
            [24, 12, 8, 6]
        )
        self.assertEqual(
            Solution().productExceptSelf([1]),
            [1]
        )
