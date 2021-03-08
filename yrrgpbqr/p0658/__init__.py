import unittest
from typing import List


class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        l, r = -1, len(arr)
        while r - l > 1:
            m = (l + r) // 2
            if arr[m] < x:
                l = m
            else:
                r = m
        if 0 <= l and r < len(arr):
            if abs(x - arr[l]) > abs(x - arr[r]):
                l = r
                r = r + 1
        elif l == -1:
            l = r
            r = r + 1
        # l points to closest element
        while 0 < l and r < len(arr) and r - l < k:
            if abs(x - arr[l - 1]) > abs(x - arr[r]):
                r += 1
            else:
                l -= 1
        if l == 0:
            r = k
        if r == len(arr):
            l = len(arr) - k
        return arr[l:r]


class Test(unittest.TestCase):
    def test(self):
        arr = [1, 2, 3, 4, 5]
        k = 4
        x = 3
        out = [1, 2, 3, 4]
        self.assertEqual(Solution().findClosestElements(arr, k, x), out)
        arr = [1, 2, 3, 4, 5]
        k = 3
        x = 3
        out = [2, 3, 4]
        self.assertEqual(Solution().findClosestElements(arr, k, x), out)
        arr = [1, 2, 3, 4, 5]
        k = 2
        x = 3
        out = [2, 3]
        self.assertEqual(Solution().findClosestElements(arr, k, x), out)
        arr = [1, 2, 3, 4, 5]
        k = 1
        x = 3
        out = [3]
        self.assertEqual(Solution().findClosestElements(arr, k, x), out)
        arr = [1, 2, 3, 4, 5]
        k = 4
        x = -1
        out = [1, 2, 3, 4]
        self.assertEqual(Solution().findClosestElements(arr, k, x), out)
