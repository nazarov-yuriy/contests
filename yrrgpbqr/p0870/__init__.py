import unittest
from typing import List


class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        bi = sorted((x, i) for i, x in enumerate(B))
        skipped = []
        bpos = 0
        res = [None] * len(B)
        for num in sorted(A):
            if num > bi[bpos][0]:
                res[bi[bpos][1]] = num
                bpos += 1
            else:
                skipped.append(num)
        for i in range(len(B)):
            if res[i] is None:
                res[i] = skipped.pop()
        return res


class Test(unittest.TestCase):
    def test(self):
        A = [2, 7, 11, 15]
        B = [1, 10, 4, 11]
        out = [2, 11, 7, 15]
        self.assertEqual(Solution().advantageCount(A, B), out)
        A = [12, 24, 8, 32]
        B = [13, 25, 32, 11]
        out = [24, 32, 8, 12]
        self.assertEqual(Solution().advantageCount(A, B), out)
