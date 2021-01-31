import unittest
from typing import List


class Fancy:
    def __init__(self):
        self.cache = {}
        self.nums = []
        self.current_bias = 0
        self.current_multiplier = 1
        self.inverse_multiplier = 1
        self.modulus = 10**9 + 7
        self.inv = [self.inverse(x) for x in range(101)]

    def inverse(self, x):
        z = x
        for i in range(9):
            z = (z ** 10) % self.modulus
        y = (x * x) % self.modulus
        y = (y * y) % self.modulus
        y = (y * x) % self.modulus
        return (z * y) % self.modulus
        # return (x ** (self.modulus - 2)) % self.modulus

    def append(self, val: int) -> None:
        x = (val - self.current_bias) % self.modulus
        x = (x * self.inverse_multiplier) % self.modulus
        self.nums.append(x)

    def multAll(self, m: int) -> None:
        self.current_multiplier = (m * self.current_multiplier) % self.modulus
        self.inverse_multiplier = (self.inv[m] * self.inverse_multiplier) % self.modulus
        self.current_bias = (m * self.current_bias) % self.modulus

    def addAll(self, inc: int) -> None:
        self.current_bias = (inc + self.current_bias) % self.modulus

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.nums):
            return -1
        res = self.nums[idx]
        res *= self.current_multiplier
        res += self.current_bias
        return res % (10**9 + 7)


class Test(unittest.TestCase):
    def test(self):
        obj = Fancy()
        obj.append(1)
        obj.addAll(2)
        for i in range(100000):
            obj.multAll(91)
        for i in range(10000):
            self.assertEqual(obj.getIndex(0), 271604643)
        self.assertEqual(obj.getIndex(0), 271604643)
