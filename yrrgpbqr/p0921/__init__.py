import unittest
from typing import List


class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        balance = 0
        min_balance = 0
        for char in S:
            balance += {"(": 1, ")": -1}.get(char, 0)
            min_balance = min(min_balance, balance)
        return -2 * min_balance + balance


class Test(unittest.TestCase):
    def test(self):
        s = ""
        self.assertEqual(Solution().minAddToMakeValid(s), 0)
        s = "())"
        self.assertEqual(Solution().minAddToMakeValid(s), 1)
        s = "((("
        self.assertEqual(Solution().minAddToMakeValid(s), 3)
        s = "()"
        self.assertEqual(Solution().minAddToMakeValid(s), 0)
        s = "()))(("
        self.assertEqual(Solution().minAddToMakeValid(s), 4)
