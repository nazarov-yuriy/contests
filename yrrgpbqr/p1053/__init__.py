import unittest
from typing import List


class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        pos = len(arr) - 2
        prev = arr[-1]
        while pos >= 0:
            if arr[pos] <= prev:
                prev = arr[pos]
                pos -= 1
            else:
                break
        if pos == -1:
            return arr
        swap_with = max((x, -i) for i, x in enumerate(arr) if pos < i and x < arr[pos])
        arr[pos], arr[-swap_with[1]] = arr[-swap_with[1]], arr[pos]
        return arr


class Test(unittest.TestCase):
    def test(self):
        arr = [3, 2, 1]
        out = [3, 1, 2]
        self.assertEqual(Solution().prevPermOpt1(arr), out)
        arr = [1, 1, 5]
        out = [1, 1, 5]
        self.assertEqual(Solution().prevPermOpt1(arr), out)
        arr = [1, 9, 4, 6, 7]
        out = [1, 7, 4, 6, 9]
        self.assertEqual(Solution().prevPermOpt1(arr), out)
        arr = [3, 1, 1, 3]
        out = [1, 3, 1, 3]
        self.assertEqual(Solution().prevPermOpt1(arr), out)
