import unittest
from typing import List


class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        edits_left = 1
        s_pos, t_pos = 0, 0
        while s_pos < len(s) and t_pos < len(t):
            if s[s_pos] != t[t_pos]:
                if edits_left > 0:
                    edits_left -= 1
                    if len(s) < len(t): # insert
                        t_pos += 1
                    elif len(s) > len(t): # delete
                        s_pos += 1
                    else: # replace
                        s_pos += 1
                        t_pos += 1
                else:
                    return False
            else:
                s_pos += 1
                t_pos += 1
        return s_pos + t_pos + edits_left == len(s) + len(t)


class Test(unittest.TestCase):
    def test(self):
        s = "ab"
        t = "acb"
        self.assertEqual(Solution().isOneEditDistance(s, t), True)
        s = ""
        t = ""
        self.assertEqual(Solution().isOneEditDistance(s, t), False)
        s = "a"
        t = ""
        self.assertEqual(Solution().isOneEditDistance(s, t), True)
        s = ""
        t = "a"
        self.assertEqual(Solution().isOneEditDistance(s, t), True)
        s = "ab"
        t = "acd"
        self.assertEqual(Solution().isOneEditDistance(s, t), False)
