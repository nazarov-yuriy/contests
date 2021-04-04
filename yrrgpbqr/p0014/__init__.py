import unittest
from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        prefix = list(strs[0])
        prefix_len = len(prefix)
        for s in strs[1:]:
            prefix_len = min(prefix_len, len(s))
            for i, char in enumerate(s[:prefix_len]):
                if char != prefix[i]:
                    prefix_len = i
                    break
        return "".join(prefix[:prefix_len])


class Test(unittest.TestCase):
    def test(self):
        strs = ["flower", "flow", "flight"]
        out = "fl"
        self.assertEqual(Solution().longestCommonPrefix(strs), out)
        strs = ["dog", "racecar", "car"]
        out = ""
        self.assertEqual(Solution().longestCommonPrefix(strs), out)
