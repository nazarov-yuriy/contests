import unittest


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) < 2:
            return len(s)
        present = set()
        begin, end, res = 0, 0, 0
        while end < len(s):
            while s[end] in present:
                present.remove(s[begin])
                begin += 1
            present.add(s[end])
            end += 1
            res = max(res, end - begin)
        return res


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().lengthOfLongestSubstring("abcabcbb"), 3)
        self.assertEqual(Solution().lengthOfLongestSubstring("bbbbb"), 1)
        self.assertEqual(Solution().lengthOfLongestSubstring("pwwkew"), 3)
        self.assertEqual(Solution().lengthOfLongestSubstring(""), 0)
