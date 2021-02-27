import unittest
from typing import List


class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        stack = [0]
        pos = 0
        for char in S:
            if char == '(':
                stack.append(0)
            else:
                if stack[-1] == 0:
                    stack.pop()
                    stack[-1] += 1
                else:
                    el = stack.pop() * 2
                    stack[-1] += el
        return stack[-1]


class Test(unittest.TestCase):
    def test(self):
        S = "()"
        out = 1
        self.assertEqual(Solution().scoreOfParentheses(S), out)
        S = "(())"
        out = 2
        self.assertEqual(Solution().scoreOfParentheses(S), out)
        S = "()()"
        out = 2
        self.assertEqual(Solution().scoreOfParentheses(S), out)
        S = "(()(()))"
        out = 6
        self.assertEqual(Solution().scoreOfParentheses(S), out)
