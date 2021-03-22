import unittest
from typing import List


class Solution:
    def checkValidString(self, s: str) -> bool:
        open = 0
        vacant = 0
        for char in s:
            if char == '(':
                open += 1
            if char == ')':
                if open > 0:
                    open -= 1
                elif vacant > 0:
                    vacant -= 1
                else:
                    return False
            if char == '*':
                vacant += 1
        open = 0
        vacant = 0
        for char in reversed(s):
            if char == ')':
                open += 1
            if char == '(':
                if open > 0:
                    open -= 1
                elif vacant > 0:
                    vacant -= 1
                else:
                    return False
            if char == '*':
                vacant += 1
        return True


class Test(unittest.TestCase):
    def test(self):
        s = "()"
        out = True
        self.assertEqual(Solution().checkValidString(s), out)
        s = "(*)"
        out = True
        self.assertEqual(Solution().checkValidString(s), out)
        s = "(*))"
        out = True
        self.assertEqual(Solution().checkValidString(s), out)
