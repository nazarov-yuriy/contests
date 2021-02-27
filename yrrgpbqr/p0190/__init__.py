import unittest
from typing import List


class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            if n & (1 << i):
                res |= (1 << (31 - i))
        return res


class Test(unittest.TestCase):
    def test(self):
        n = 0b00000010100101000001111010011100
        out = 964176192
        self.assertEqual(Solution().reverseBits(n), out)
