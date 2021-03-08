import unittest
from typing import List


class Solution:
    def removeDuplicates(self, s: str) -> str:
        k = 2
        stack = []  # (char, count)
        for char in s:
            if len(stack) > 0 and stack[-1][0] == char:
                stack[-1][1] += 1
                if stack[-1][1] == k:
                    stack.pop()
            else:
                stack.append([char, 1])
        res = ""
        for char, count in stack:
            for _ in range(count):
                res += char
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "abcd"
        out = "abcd"
        self.assertEqual(Solution().removeDuplicates(s), out)
        s = "abbaca"
        out = "ca"
        self.assertEqual(Solution().removeDuplicates(s), out)
        s = "pbbcggttciiippooaais"
        out = "ps"
        self.assertEqual(Solution().removeDuplicates(s), out)
