import unittest
from typing import List
import collections


class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        counters = collections.Counter()
        INF = len(A) + 1

        candidates = {('A', A[0]), ('A', B[0]), ('B', A[0]), ('B', B[0])} # A1 A2 B1 B2
        for candidate in candidates:
            counters[candidate] = 0
        for a_val, b_val in zip(A, B):
            for candidate in candidates:
                if candidate[0] == 'A':
                    if candidate[1] == a_val:
                        pass
                    elif candidate[1] == b_val:
                        counters[candidate] += 1
                    else:
                        counters[candidate] = INF
                else:
                    if candidate[1] == b_val:
                        pass
                    elif candidate[1] == a_val:
                        counters[candidate] += 1
                    else:
                        counters[candidate] = INF
        res = min(counters.values())
        if res >= INF:
            return -1
        else:
            return res


class Test(unittest.TestCase):
    def test(self):
        A = [2,1,2,4,2,2]
        B = [5,2,6,2,3,2]
        self.assertEqual(Solution().minDominoRotations(A, B), 2)
