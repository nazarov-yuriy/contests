import unittest
from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        l, r = 0, len(s) - 1
        while l < r:
            s[l], s[r] = s[r], s[l]
            l += 1
            r -= 1


class Test(unittest.TestCase):
    def test(self):
        s = ["h","e","l","l","o"]
        out = ["o","l","l","e","h"]
        Solution().reverseString(s)
        self.assertEqual(s, out)
