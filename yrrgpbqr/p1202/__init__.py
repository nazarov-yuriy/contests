import unittest
from typing import List
from collections import deque


class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        pairs_dict = {}
        for a, b in pairs:
            pairs_dict.setdefault(a, set()).add(b)
            pairs_dict.setdefault(b, set()).add(a)
        components = [None] * len(s)
        for i in range(len(s)):
            q = deque([i])
            while len(q):
                pos = q.popleft()
                if components[pos] is None:
                    components[pos] = i
                    for to in pairs_dict.get(pos, []):
                        q.append(to)
        positions = {}
        for i, c in enumerate(components):
            positions.setdefault(c, set()).add(i)

        res = list(s)
        for component in positions.values():
            component = sorted(component)
            sorted_chars = sorted([s[x] for x in component])
            for i, pos in enumerate(component):
                res[pos] = sorted_chars[i]
        return "".join(res)


class Test(unittest.TestCase):
    def test(self):
        s = "dcab"
        pairs = [[0, 3], [1, 2]]
        self.assertEqual(
            "bacd",
            Solution().smallestStringWithSwaps(s, pairs)
        )
        s = "dcab"
        pairs = [[0, 3], [1, 2], [0, 2]]
        self.assertEqual(
            "abcd",
            Solution().smallestStringWithSwaps(s, pairs)
        )
        s = "cba"
        pairs = [[0, 1], [1, 2]]
        self.assertEqual(
            "abc",
            Solution().smallestStringWithSwaps(s, pairs)
        )
        s = "yhiihxbordwyjybyt"
        pairs = [
            [9, 1], [5, 11], [9, 7], [2, 7], [14, 16], [6, 16], [0, 5], [12, 9], [6, 5], [9, 10],
            [4, 7], [3, 2], [10, 1], [3, 15], [12, 4], [10, 10], [15, 12]
        ]
        self.assertEqual(
            "bdhhibtirjoxwyyyy",
            Solution().smallestStringWithSwaps(s, pairs)
        )
        s = "xwwbesrhlaoucciymqe"
        pairs = [
            [12, 5], [17, 8], [0, 8], [8, 13], [16, 10], [4, 15], [11, 12], [2, 11], [14, 7], [13, 18], [1, 10], [4, 8],
            [2, 17], [8, 1], [15, 13], [16, 12], [16, 18], [13, 11], [12, 0]
        ]
        self.assertEqual(
            "ccebelrhmaoqsuiwwxy",
            Solution().smallestStringWithSwaps(s, pairs)
        )
