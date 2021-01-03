import unittest


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if (divisor >= 0) == (dividend >= 0):
            sign = 1
        else:
            sign = -1
        divisor = abs(divisor)  # may produce overflow in int32
        dividend = abs(dividend)  # ma produce overflow in int32
        shifted_divisor = divisor
        shift = 0
        while shifted_divisor < dividend:
            shifted_divisor <<= 1
            shift += 1
        res = 0
        while shift >= 0:
            if shifted_divisor <= dividend:
                res += 1 << shift
                dividend -= shifted_divisor
            shift -= 1
            shifted_divisor >>= 1
        if sign > 0:
            res = min(2**31-1, res)
        return res if sign > 0 else -res


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().divide(10, 3), 3)
        self.assertEqual(Solution().divide(7, -3), -2)
        self.assertEqual(Solution().divide(0, 1), 0)
        self.assertEqual(Solution().divide(1, 1), 1)
        self.assertEqual(Solution().divide(0, -1), 0)
        self.assertEqual(Solution().divide(-2**31, -1), 2**31-1)
        self.assertEqual(Solution().divide(-2**31, 1), -2**31)
