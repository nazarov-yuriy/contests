import unittest
from typing import List


class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        x_pow = 1
        res = set()
        while x_pow <= bound:
            y_pow = 1
            while x_pow + y_pow <= bound:
                res.add(x_pow + y_pow)
                if y == 1:
                    break
                else:
                    y_pow *= y
            if x == 1:
                break
            else:
                x_pow *= x
        return list(sorted(res))


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            [2, 3, 4, 5, 7, 9, 10],
            Solution().powerfulIntegers(2, 3, 10)
        )
