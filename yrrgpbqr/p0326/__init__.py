import unittest
from typing import List


class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        max_int_3_power = 3 ** 19
        return max_int_3_power % n == 0


class Test(unittest.TestCase):
    def test(self):
        n = 27
        out = True
        self.assertEqual(Solution().isPowerOfThree(n), out)
        n = 0
        out = False
        self.assertEqual(Solution().isPowerOfThree(n), out)
        n = 9
        out = True
        self.assertEqual(Solution().isPowerOfThree(n), out)
        n = 45
        out = False
        self.assertEqual(Solution().isPowerOfThree(n), out)
