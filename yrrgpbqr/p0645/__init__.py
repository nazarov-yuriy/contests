import unittest
from typing import List
from collections import Counter
import itertools


class Solution:  # Lazy solution
    def findErrorNums(self, nums: List[int]) -> List[int]:
        c = Counter(itertools.chain(range(1, len(nums)+1), nums))
        return [[x for x in c if c[x] == 3][0], [x for x in c if c[x] == 1][0]]


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 2, 2, 4]
        out = [2, 3]
        self.assertEqual(Solution().findErrorNums(nums), out)
