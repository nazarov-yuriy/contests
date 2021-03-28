import unittest
from typing import List
from collections import Counter


class Solution:
    def reorderedPowerOf2(self, N: int) -> bool:
        for i in range(31):
            if Counter(str(N)) == Counter(str(1 << i)):
                return True
        return False


class Test(unittest.TestCase):
    def test(self):
        N = 1
        out = True
        self.assertEqual(Solution().reorderedPowerOf2(N), out)
        N = 10
        out = False
        self.assertEqual(Solution().reorderedPowerOf2(N), out)
        N = 16
        out = True
        self.assertEqual(Solution().reorderedPowerOf2(N), out)
        N = 24
        out = False
        self.assertEqual(Solution().reorderedPowerOf2(N), out)
        N = 46
        out = True
        self.assertEqual(Solution().reorderedPowerOf2(N), out)
