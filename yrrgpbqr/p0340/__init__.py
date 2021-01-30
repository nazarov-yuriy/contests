import unittest
from typing import List
import collections


class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        if k == 0:
            return 0
        l, r = 0, 0  # including
        c = collections.Counter([s[0]])
        res = 0
        while True:
            if len(c) <= k:
                res = max(res, r - l + 1)
                if r >= len(s) - 1:
                    break
                else:
                    r += 1
                    c[s[r]] += 1
            else:
                c[s[l]] -= 1
                if c[s[l]] == 0:
                    del c[s[l]]
                l += 1
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "eceba"
        k = 2
        out = 3
        self.assertEqual(Solution().lengthOfLongestSubstringKDistinct(s, k), out)
        s = "aa"
        k = 1
        out = 2
        self.assertEqual(Solution().lengthOfLongestSubstringKDistinct(s, k), out)
