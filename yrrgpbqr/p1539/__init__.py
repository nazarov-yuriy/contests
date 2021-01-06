import unittest
from typing import List
from itertools import chain


class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        for i, num in enumerate(chain(arr, [3000])):
            if num - (i + 1) >= k:
                return num - ((num - (i + 1)) - k + 1)


class Test(unittest.TestCase):
    def test(self):
        arr = [2, 3, 4, 7, 11]
        k = 5
        self.assertEqual(Solution().findKthPositive(arr, k), 9)
        arr = [1, 2, 3, 4]
        k = 2
        self.assertEqual(Solution().findKthPositive(arr, k), 6)
        arr = []
        k = 2
        self.assertEqual(Solution().findKthPositive(arr, k), 2)
