import unittest
from typing import List


class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
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
        k = 2
        out = "abcd"
        self.assertEqual(Solution().removeDuplicates(s, k), out)
        s = "deeedbbcccbdaa"
        k = 3
        out = "aa"
        self.assertEqual(Solution().removeDuplicates(s, k), out)
        s = "pbbcggttciiippooaais"
        k = 2
        out = "ps"
        self.assertEqual(Solution().removeDuplicates(s, k), out)
