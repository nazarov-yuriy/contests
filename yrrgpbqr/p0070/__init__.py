import unittest
from typing import List


class Solution:
    def climbStairs(self, n: int) -> int:
        cache = [1] + [None] * n

        def climb(n):
            if cache[n] is None:
                res = 0
                if n - 2 >= 0:
                    res += climb(n - 2)
                if n - 1 >= 0:
                    res += climb(n - 1)
                cache[n] = res
            return cache[n]

        return climb(n)


class Test(unittest.TestCase):
    def test(self):
        m = 2
        out = 2
        self.assertEqual(Solution().climbStairs(m), out)
        m = 3
        out = 3
        self.assertEqual(Solution().climbStairs(m), out)
        m = 4
        out = 5
        self.assertEqual(Solution().climbStairs(m), out)
