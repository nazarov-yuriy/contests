import unittest
from typing import List


class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        code = 0
        for i in range(k):
            code <<= 1
            code += int(s[i])
        codes = [0] * (2 ** k)
        codes[code] = 1
        for i in range(k, len(s)):
            code <<= 1
            code += int(s[i])
            code = code % (2 ** k)
            codes[code] = 1
        return sum(codes) == 2 ** k


class Test(unittest.TestCase):
    def test(self):
        s = "001101"
        k = 2
        out = True
        self.assertEqual(Solution().hasAllCodes(s, k), out)
