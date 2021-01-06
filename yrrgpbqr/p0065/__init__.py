import unittest
from typing import List


class Solution:
    def isInteger(self, s: str) -> bool:
        for char in s:
            if not ("0" <= char <= "9"):
                return False
        return len(s) > 0

    def clearSign(self, s: str) -> str:
        if s.startswith("-") or s.startswith("+"):
            return s[1:]
        return s

    def isNumber(self, s: str) -> bool:
        if "e" in s:
            num, e10 = s.strip().split("e", 1)
        else:
            num, e10 = s.strip(), "0"
        num = self.clearSign(num)
        e10 = self.clearSign(e10)
        if "." in num:
            whole, frac = num.split(".", 1)
            if whole == "" and frac != "":
                whole = "0"
            elif frac == "" and whole != "":
                frac = "0"
        else:
            whole, frac = num, "0"
        return self.isInteger(whole) and self.isInteger(frac) and self.isInteger(e10)


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().isNumber("0"), True)
        self.assertEqual(Solution().isNumber(" 0.1"), True)
        self.assertEqual(Solution().isNumber("abc"), False)
        self.assertEqual(Solution().isNumber("1 a"), False)
        self.assertEqual(Solution().isNumber("2e10"), True)
        self.assertEqual(Solution().isNumber(" -90e3  "), True)
        self.assertEqual(Solution().isNumber(" 1e"), False)
        self.assertEqual(Solution().isNumber("e3"), False)
        self.assertEqual(Solution().isNumber(" 6e-1"), True)
        self.assertEqual(Solution().isNumber(" 99e2.5"), False)
        self.assertEqual(Solution().isNumber("53.5e93"), True)
        self.assertEqual(Solution().isNumber(" --6 "), False)
        self.assertEqual(Solution().isNumber("-+3"), False)
        self.assertEqual(Solution().isNumber("95a54e53"), False)
