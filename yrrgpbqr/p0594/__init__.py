import unittest
from typing import List
import collections


class Solution:
    def findLHS(self, nums: List[int]) -> int:
        c = collections.Counter(nums)
        res = 0
        for num in nums:
            if c[num] > 0 and c[num+1] > 0:
                res = max(res, c[num] + c[num+1])
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 3, 2, 2, 5, 2, 3, 7]
        self.assertEqual(Solution().findLHS(nums), 5)
