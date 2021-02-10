import unittest
from typing import List


class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        prev = - len(s)
        res = []
        pos = 0
        for i, char in enumerate(s):
            if char == c:
                while pos <= i:
                    res.append(min(pos - prev, i - pos))
                    pos += 1
                prev = i
        while pos < len(s):
            res.append(pos - prev)
            pos += 1
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "loveleetcode"
        c = "e"
        out = [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
        self.assertEqual(Solution().shortestToChar(s, c), out)
        s = "e"
        c = "e"
        out = [0]
        self.assertEqual(Solution().shortestToChar(s, c), out)
        s = "aaab"
        c = "b"
        out = [3, 2, 1, 0]
        self.assertEqual(Solution().shortestToChar(s, c), out)
