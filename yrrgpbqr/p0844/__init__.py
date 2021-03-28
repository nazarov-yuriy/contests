import unittest
from typing import List


class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        stack_s = []
        for char in S:
            if char == "#":
                if len(stack_s) > 0:
                    stack_s.pop()
            else:
                stack_s.append(char)
        stack_t = []
        for char in T:
            if char == "#":
                if len(stack_t) > 0:
                    stack_t.pop()
            else:
                stack_t.append(char)
        return stack_s == stack_t


class Test(unittest.TestCase):
    def test(self):
        S = "ab#c"
        T = "ad#c"
        out = True
        self.assertEqual(Solution().backspaceCompare(S, T), out)
        S = "a#c"
        T = "b"
        out = False
        self.assertEqual(Solution().backspaceCompare(S, T), out)

