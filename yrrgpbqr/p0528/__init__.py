import unittest
from typing import List
from random import random
from collections import Counter


class Solution:
    def __init__(self, w: List[int]):
        self.w = w
        prefix_sum = [0]
        sum = 0
        for weight in w:
            sum += weight
            prefix_sum.append(sum)
        self.prefix_sum = prefix_sum

    def pickIndex(self) -> int:
        pos = random() * self.prefix_sum[-1]
        l, r = 0, len(self.w)
        while True:
            m = (l + r) // 2
            if self.prefix_sum[m] > pos:
                r = m
            elif self.prefix_sum[m + 1] < pos:
                l = m + 1
            else:
                return m


class Test(unittest.TestCase):
    def test(self):
        s = Solution([1, 1, 1, 2])
        c = Counter()
        for _ in range(10000):
            i = s.pickIndex()
            c[i] += 1
        print(c)