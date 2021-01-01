import unittest


class Solution:
    def reverse(self, x: int) -> int:
        if x >= 0:
            sign = 1
        else:
            sign = -1
            x = -x
        res = 0
        while x:
            t = 0
            for _ in range(10):
                t += res
                if t > 2**31-1:  # negative in int32. -2147483648 isn't handled because -8463847412 coudn't be passed to input
                    return 0  # overflow
            res *= 10
            res += x % 10
            x = x // 10
        return sign * res


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().reverse(123), 321)
        self.assertEqual(Solution().reverse(-123), -321)
        self.assertEqual(Solution().reverse(120), 21)
        self.assertEqual(Solution().reverse(0), 0)
        self.assertEqual(Solution().reverse(1234567899), 0)
        self.assertEqual(Solution().reverse(1234567892), 0)
        self.assertEqual(Solution().reverse(1234567891), 1987654321)
