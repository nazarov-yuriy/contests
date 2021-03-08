import unittest
from typing import List


class Solution:
    def matchQuestion(self, s, p):
        if len(s) != len(p):
            return False
        if "?" not in p:
            return s == p
        else:
            for sc, pc in zip(s, p):
                if pc != "?" and pc != sc:
                    return False
        return True

    def isMatch(self, s: str, p: str) -> bool:
        if "*" not in p:
            return self.matchQuestion(s, p)

        while "**" in p:
            p = p.replace("**", "*")
        seqs = p.split("*")
        pos = 0
        s_len = len(s)
        for seq in seqs:
            seq_len = len(seq)
            while pos + seq_len <= s_len and not self.matchQuestion(s[pos:pos + seq_len], seq):
                pos += 1
            if not self.matchQuestion(s[pos:pos + seq_len], seq):
                return False
            else:
                pos = pos + seq_len
        res = True
        if not p.endswith("*"):
            res = res and self.matchQuestion(s[-len(seqs[-1]):], seqs[-1])
        if not p.startswith("*"):
            res = res and self.matchQuestion(s[:len(seqs[0])], seqs[0])
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "aa"
        p = "a"
        out = False
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "aa"
        p = "*"
        out = True
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "cb"
        p = "?a"
        out = False
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "adceb"
        p = "*a*b"
        out = True
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "acdcb"
        p = "a*c?b"
        out = False
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba"
        p = "a*******b"
        out = False
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb"
        p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"
        out = False
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "abcabczzzde"
        p = "*abc???de*"
        out = True
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "aaab"
        p = "b**"
        out = False
        self.assertEqual(Solution().isMatch(s, p), out)
