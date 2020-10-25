import unittest
from typing import List
import functools
import itertools
import operator


class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        not_negative = sorted(x for x in nums if x >= 0)
        negative = sorted(x for x in nums if x < 0)
        res = None
        k = 3
        for num_negative in range(0, k + 1):
            num_not_negative = k - num_negative
            if num_negative <= len(negative) and num_not_negative <= len(not_negative):
                if num_negative % 2 == 1:
                    max_product = functools.reduce(
                        operator.mul, itertools.chain(negative[-num_negative:], not_negative[:num_not_negative]))
                else:
                    max_product = functools.reduce(operator.mul, itertools.chain(
                        negative[:num_negative], not_negative[-num_not_negative:]))
                if res is None:
                    res = max_product
                else:
                    res = max(res, max_product)
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 2, 3]
        self.assertEqual(Solution().maximumProduct(nums), 6)
        nums = [1, 2, 3, 4]
        self.assertEqual(Solution().maximumProduct(nums), 24)
        nums = [-5, 1, 2, 3, 4]
        self.assertEqual(Solution().maximumProduct(nums), 24)
        nums = [-5, -5, 1, 2, 3, 4]
        self.assertEqual(Solution().maximumProduct(nums), 100)
        nums = [-1, -1, -1, -2]
        self.assertEqual(Solution().maximumProduct(nums), -1)
        nums = [-1, -1, -1, 0]
        self.assertEqual(Solution().maximumProduct(nums), 0)
