import unittest
from typing import List


class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        rot = {"0": "0", "1": "1", "6": "9", "8": "8", "9": "6"}
        for fwd, bwd in zip(num, reversed(num)):
            if fwd != rot.get(bwd, ""):
                return False
        return True


class Test(unittest.TestCase):
    def test(self):
        num = "69"
        out = True
        self.assertEqual(Solution().isStrobogrammatic(num), out)
        num = "88"
        out = True
        self.assertEqual(Solution().isStrobogrammatic(num), out)
        num = "962"
        out = False
        self.assertEqual(Solution().isStrobogrammatic(num), out)
        num = "1"
        out = True
        self.assertEqual(Solution().isStrobogrammatic(num), out)
