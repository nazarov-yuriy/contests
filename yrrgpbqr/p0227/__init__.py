import unittest
from typing import List


class Solution:
    def calcMultDiv(self, chars):
        res = 1
        op = "*"
        part = []
        for char in chars:
            if char in {"*", "/"}:
                if op == "*":
                    res *= int("".join(part))
                else:
                    res //= int("".join(part))
                op = char
                part = []
            else:
                part.append(char)
        if op == "*":
            res *= int("".join(part))
        else:
            res //= int("".join(part))
        return res

    def calculate(self, s: str) -> int:
        chars = list(s.replace(" ", ""))
        res = 0
        op = "+"
        part = []
        for char in chars:
            if char in {"+", "-"}:
                res += self.calcMultDiv(part) * (1 if op == "+" else -1)
                op = char
                part = []
            else:
                part.append(char)
        res += self.calcMultDiv(part) * (1 if op == "+" else -1)
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "3+2*2"
        self.assertEqual(Solution().calculate(s), 7)
        s = "3/2"
        self.assertEqual(Solution().calculate(s), 1)
        s = "3+5/2"
        self.assertEqual(Solution().calculate(s), 5)
        s = "3-5/2"
        self.assertEqual(Solution().calculate(s), 1)
