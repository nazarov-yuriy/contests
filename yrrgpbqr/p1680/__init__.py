import unittest
from typing import List


class Solution:
    # A bit cheaty(
    def concatenatedBinary(self, n: int) -> int:
        numbers = ["0b"]
        for num in range(1, n + 1):
            numbers.append(bin(num)[2:])
        res = int("".join(numbers), 2)
        return res % (10**9 + 7)


class Test(unittest.TestCase):
    def test(self):
        n = 1
        out = 1
        self.assertEqual(Solution().concatenatedBinary(n), out)
        n = 3
        out = 27
        self.assertEqual(Solution().concatenatedBinary(n), out)
        n = 12
        out = 505379714
        self.assertEqual(Solution().concatenatedBinary(n), out)
        n = 100000
        out = 757631812
        self.assertEqual(Solution().concatenatedBinary(n), out)
