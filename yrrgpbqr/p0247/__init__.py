import unittest
from typing import List
from itertools import product


class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        rot = {"0": "0", "1": "1", "6": "9", "8": "8", "9": "6"}
        prefixes = [["0", "1", "6", "8", "9"] for _ in range(n // 2)]
        res = []
        if n % 2 == 1:
            prefixes += [["0", "1", "8"]]
            for prefix in product(*prefixes):
                if prefix[0] == "0" and n > 1:
                    continue
                res.append("".join(prefix) + "".join(rot[x] for x in reversed(prefix[:-1])))
        else:
            for prefix in product(*prefixes):
                if prefix[0] == "0" and n > 1:
                    continue
                res.append("".join(prefix) + "".join(rot[x] for x in reversed(prefix)))
        return res


class Test(unittest.TestCase):
    def test(self):
        n = 1
        out = ["0", "1", "8"]
        self.assertEqual(Solution().findStrobogrammatic(n), out)
        n = 2
        out = ["11", "69", "88", "96"]
        self.assertEqual(Solution().findStrobogrammatic(n), out)
        n = 3
        out = ["101", "111", "181", "609", "619", "689", "808", "818", "888", "906", "916", "986"]
        self.assertEqual(Solution().findStrobogrammatic(n), out)
