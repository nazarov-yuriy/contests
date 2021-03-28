import unittest
from typing import List


class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = []
        res = [0] * len(T)
        for i, t in enumerate(T):
            while len(stack) > 0 and stack[-1][1] < t:
                pi, pt = stack.pop()
                res[pi] = i - pi
            stack.append((i, t))
        return res


class Test(unittest.TestCase):
    def test(self):
        T = [73, 74, 75, 71, 69, 72, 76, 73]
        out = [1, 1, 4, 2, 1, 1, 0, 0]
        self.assertEqual(Solution().dailyTemperatures(T), out)
