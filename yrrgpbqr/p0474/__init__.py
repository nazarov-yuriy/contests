import unittest
from typing import List
import collections


class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        res = [[0] * (n + 1) for _ in range(m + 1)]
        max_res = 0
        for s in strs:
            c = collections.Counter(s)
            z, o = c['0'], c['1']
            for mi in range(m, -1, -1):
                for ni in range(n, -1, -1):
                    if mi + z <= m and ni + o <= n:
                        res[mi + z][ni + o] = max(1 + res[mi][ni], res[mi + z][ni + o])
                        max_res = max(max_res, res[mi + z][ni + o])
        return max_res


class Test(unittest.TestCase):
    def test(self):
        strs = ["10", "0001", "111001", "1", "0"]
        m = 5
        n = 3
        out = 4
        self.assertEqual(Solution().findMaxForm(strs, m, n), out)
        strs = ["10", "0", "1"]
        m = 1
        n = 1
        out = 2
        self.assertEqual(Solution().findMaxForm(strs, m, n), out)
