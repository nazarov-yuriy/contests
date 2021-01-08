import unittest
from typing import List
from collections import Counter
import random


class Solution:
    def __init__(self, nums: List[int]):
        self.positions = {}
        for i, num in enumerate(nums):
            self.positions.setdefault(num, []).append(i)

    def pick(self, target: int) -> int:
        positions = self.positions[target]
        return positions[int(random.random() * len(positions))]


class Test(unittest.TestCase):
    def test(self):
        N = 10000
        nums = [1, 2, 3, 3, 3]
        obj = Solution(nums)
        target = 3
        c = Counter(obj.pick(target) for _ in range(N))
        assert c[2] > 0.3 * N
        assert c[3] > 0.3 * N
        assert c[4] > 0.3 * N
