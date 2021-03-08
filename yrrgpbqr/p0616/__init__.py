import unittest
from typing import List


class Solution:
    def addBoldTag(self, s: str, dict: List[str]) -> str:
        trie = {}
        for word in dict:
            node = trie
            for char in word:
                node = node.setdefault(char, {})
            node["#"] = None  # EOS
        l, r = 0, 0
        res = []
        for i in range(len(s)):
            pos = i
            node = trie
            while pos < len(s) and s[pos] in node:
                node = node[s[pos]]
                pos += 1
                if "#" in node:
                    if l <= i <= r:
                        r = max(r, pos)
                    else:
                        if (l, r) != (0, 0):
                            res.append((l, r))
                        l, r = i, pos
        if (l, r) != (0, 0):
            res.append((l, r))

        if len(res) == 0:
            return s
        pos = 0
        l, r = res[pos]
        res_str = ""
        for i, char in enumerate(s):
            if i == l:
                res_str += "<b>"
            res_str += char
            if i == r - 1:
                res_str += "</b>"
                pos = min(pos + 1, len(res) - 1)
                l, r = res[pos]
        return res_str


class Test(unittest.TestCase):
    def test(self):
        s = "abcxyz123"
        dict = ["abc", "123"]
        out = "<b>abc</b>xyz<b>123</b>"
        self.assertEqual(Solution().addBoldTag(s, dict), out)
        s = "aaabbcc"
        dict = ["aaa","aab","bc"]
        out = "<b>aaabbc</b>c"
        self.assertEqual(Solution().addBoldTag(s, dict), out)
        s = "aaabbcc"
        dict = ["aaa", "aab", "bc", "aaabbcc"]
        out = "<b>aaabbcc</b>"
        self.assertEqual(Solution().addBoldTag(s, dict), out)
