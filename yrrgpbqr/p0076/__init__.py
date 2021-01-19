import unittest
from typing import List
from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_counter = Counter(t)
        l = 0
        r = 0
        char_counts = Counter()
        while r < len(s) and char_counts & t_counter != t_counter:
            if s[r] in t_counter:
                char_counts[s[r]] += 1
            r += 1
        if char_counts & t_counter != t_counter:
            return ""

        min_len = r - l
        min_l = l
        min_r = r
        while r <= len(s):
            if char_counts & t_counter != t_counter:
                if r == len(s):
                    break
                else:
                    if s[r] in t_counter:
                        char_counts[s[r]] += 1
                    r += 1
            else:
                cur_len = r - l
                if cur_len < min_len:
                    min_len = cur_len
                    min_l = l
                    min_r = r
                if s[l] in t_counter:
                    char_counts[s[l]] -= 1
                    if char_counts[s[l]] == 0:
                        del char_counts[s[l]]
                l += 1
        return s[min_l:min_r]


class Test(unittest.TestCase):
    def test(self):
        s = "ADOBECODEBANC"
        t = "ABC"
        self.assertEqual(Solution().minWindow(s, t), "BANC")
        s = "aa"
        t = "aa"
        self.assertEqual(Solution().minWindow(s, t), "aa")
