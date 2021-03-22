import unittest
from typing import List


class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        res = [0]
        for i, digit1 in enumerate(reversed(num1)):
            digit1 = int(digit1)
            carry = 0
            pos = i
            for digit2 in reversed(num2):
                digit2 = int(digit2)
                if pos >= len(res):
                    res.append(0)
                product = digit1 * digit2 + carry + res[pos]
                res[pos] = product % 10
                carry = product // 10
                pos += 1
            while carry > 0:
                if pos >= len(res):
                    res.append(0)
                carry += res[pos]
                res[pos] = carry % 10
                carry = carry // 10
                pos += 1
        while len(res) > 1 and res[-1] == 0:
            res.pop()
        return "".join(str(x) for x in reversed(res))


class Test(unittest.TestCase):
    def test(self):
        a, b = "0", "0"
        out = "0"
        self.assertEqual(Solution().multiply(a, b), out)
        a, b = "9", "9"
        out = "81"
        self.assertEqual(Solution().multiply(a, b), out)
        a, b = "10", "99"
        out = "990"
        self.assertEqual(Solution().multiply(a, b), out)
        a, b = "99", "10"
        out = "990"
        self.assertEqual(Solution().multiply(a, b), out)
        a, b = "11", "11"
        out = "121"
        self.assertEqual(Solution().multiply(a, b), out)
        for a in range(200):
            for b in range(2000):
                out = str(a * b)
                self.assertEqual(Solution().multiply(str(a), str(b)), out)
