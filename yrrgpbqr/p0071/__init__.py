import unittest
from typing import List


class Solution:
    def simplifyPath(self, path: str) -> str:
        parts = path.split('/')
        res = []
        for part in parts:
            if part in {"", "."}:
                pass
            elif part == "..":
                if len(res):
                    res.pop()
            else:
                res.append(part)
        return "/" + "/".join(res)


class Test(unittest.TestCase):
    def test(self):
        path = "/home/"
        out = "/home"
        self.assertEqual(Solution().simplifyPath(path), out)
