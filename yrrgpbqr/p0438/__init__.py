import unittest
from typing import List
from collections import Counter


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        pc = Counter(p)
        l, r = 0, len(p)
        sc = Counter(s[l:r])
        res = []
        if pc == sc:
            res.append(l)
        while r < len(s):
            sc[s[l]] -= 1
            if sc[s[l]] == 0:
                del sc[s[l]]
            l += 1
            sc[s[r]] += 1
            r += 1
            if pc == sc:
                res.append(l)
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "cbaebabacd"
        p = "abc"
        self.assertEqual(Solution().findAnagrams(s, p), [0, 6])
        s = "abab"
        p = "ab"
        self.assertEqual(Solution().findAnagrams(s, p), [0, 1, 2])
