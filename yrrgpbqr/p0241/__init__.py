import unittest
from typing import List


class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        ops_set = {"-", "+", "*"}
        if len(set(input) & ops_set) == 0:
            return [int(input) if input else 0]
        else:
            res = []
            for i, c in enumerate(input):
                if c in ops_set:
                    left = self.diffWaysToCompute(input[:i])
                    right = self.diffWaysToCompute(input[i+1:])
                    for l in left:
                        for r in right:
                            if c == "+":
                                val = l + r
                            elif c == "-":
                                val = l - r
                            else:
                                val = l * r
                            res.append(val)
        return sorted(res)


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            [0, 2],
            Solution().diffWaysToCompute("2-1-1")
        )
        self.assertEqual(
            [-34, -14, -10, -10, 10],
            Solution().diffWaysToCompute("2*3-4*5")
        )
