import unittest

class Solution:
    def __init__(self, bits=32):
        self.bits = bits
        self.minus_one = -1

    def do_twos_complement(self, x):
        assert x > 0
        res = 0
        for shift in range(self.bits):
            res |= 1 << shift
        carry = 1
        for shift in range(self.bits):
            if carry == 0:
                res ^= x & (1 << shift)
            else:
                if (x >> shift) & 1 != 0:
                    carry = 0
                else:
                    res ^= (1 << shift)
        return res

    def getSum(self, a: int, b: int) -> int:
        a = self.do_twos_complement(abs(a)) if a < 0 else a
        b = self.do_twos_complement(abs(b)) if b < 0 else b
        carry = 0
        res = 0
        for shift in range(self.bits):
            bit_a = (a >> shift) & 1
            bit_b = (b >> shift) & 1
            res |= (bit_a ^ bit_b ^ carry) << shift
            carry = (bit_a & bit_b) | (bit_a & carry) | (bit_b & carry)
        if res & (1 << (self.bits-1)) != 0:
            return self.minus_one * self.do_twos_complement(res)
        else:
            return res

class Test(unittest.TestCase):
    def test_ensure_twos_complement(self):
        self.assertEqual(Solution().do_twos_complement(1) + 1, 2 ** 32)
        self.assertEqual(Solution().do_twos_complement(2) + 2, 2 ** 32)
        for a in range(1, 100):
            self.assertEqual(Solution().do_twos_complement(a) + a, 2 ** 32)
        for a in range(1, 2000000000, 1000000):
            self.assertEqual(Solution().do_twos_complement(a) + a, 2 ** 32)

    def test_manual(self):
        self.assertEqual(Solution().getSum(0, 0), 0)
        self.assertEqual(Solution().getSum(1, 2), 3)

    def test_auto(self):
        for a in range(-2000000000, 2000000000, 1000000):
            for b in range(-2000000000, 2000000000, 100000001):
                if -2e9 <= a+b <= 2e9:
                    sum_res = Solution().getSum(a, b)
                    self.assertEqual(sum_res, a + b, f"a={a} b={b}")
