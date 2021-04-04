import unittest
from typing import List


class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        INF = 10 ** 5
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        smallest = [(INF, INF) for _ in range(len(envelopes) + 1)]
        res = 0
        for i, envelope in enumerate(envelopes):
            max_inner = 0
            for j in range(res, 0, -1):
                if smallest[j][0] < envelope[0] and smallest[j][1] < envelope[1]:
                    max_inner = j
                    break
            if smallest[max_inner + 1][1] > envelope[1]:
                smallest[max_inner + 1] = envelope
            res = max(res, max_inner + 1)
        return res


class Test(unittest.TestCase):
    def test(self):
        envelopes = [[5, 4], [6, 4], [6, 7], [2, 3]]
        out = 3
        self.assertEqual(Solution().maxEnvelopes(envelopes), out)
        envelopes = [[1, 1], [1, 1]]
        out = 1
        self.assertEqual(Solution().maxEnvelopes(envelopes), out)
