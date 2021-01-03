import unittest
from itertools import zip_longest


class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = []
        carry = 0
        for l, r in zip_longest(reversed(num1), reversed(num2)):
            s = int(l or "0") + int(r or "0") + carry
            res.append(str(s % 10))
            carry = s // 10
        if carry:
            res.append("1")
        return "".join(reversed(res))


class Test(unittest.TestCase):
    def test(self):
        for i in range(100):
            for j in range(i, 1000):
                self.assertEqual(Solution().addStrings(str(i), str(j)), str(i+j))
