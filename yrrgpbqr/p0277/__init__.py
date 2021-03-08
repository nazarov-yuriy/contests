import unittest
from typing import List


class Solution:
    def findCelebrity(self, n: int) -> int:
        candidates = set(range(n))
        cache = {}
        while len(candidates) > 1:
            it = iter(candidates)
            a, b = next(it), next(it)
            ab = knows(a, b)
            cache[(a, b)] = ab
            ba = knows(b, a)
            cache[(b, a)] = ba
            if ab and ba:
                candidates.remove(a)
                candidates.remove(b)
            elif ab and not ba:
                candidates.remove(a)
            elif ba and not ab:
                candidates.remove(b)
            else:
                candidates.remove(a)
                candidates.remove(b)
        if len(candidates) != 1:
            return -1
        res = next(iter(candidates))
        for i in range(n):
            if i != res:
                if (res, i) in cache:
                    if cache[(res, i)]:
                        return -1
                else:
                    if knows(res, i):
                        return -1
                if (i, res) in cache:
                    if not cache[(i, res)]:
                        return -1
                else:
                    if not knows(i, res):
                        return -1
        return res


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(1, 1)
