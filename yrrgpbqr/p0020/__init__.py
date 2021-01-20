import unittest
from typing import List


class Solution:
    def isValid(self, s: str) -> bool:
        complementary = {
            '(': ')', '{': '}', '[': ']'
        }
        stack = []
        for char in s:
            if char in complementary:
                stack.append(char)
            else:
                if len(stack) > 0 and complementary[stack[-1]] == char:
                    stack.pop()
                else:
                    return False
        return len(stack) == 0


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().isValid("()"), True)
        self.assertEqual(Solution().isValid("([)]"), False)
