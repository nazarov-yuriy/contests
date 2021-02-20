import unittest
from typing import List
from itertools import product


class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        return ["".join(p) for p in product(*[{char.lower(), char.upper()} for char in S])]


class Test(unittest.TestCase):
    def test(self):
        S = "a1b2"
        out = ["a1b2","a1B2","A1b2","A1B2"]
        self.assertEqual(sorted(Solution().letterCasePermutation(S)), sorted(out))
        S = "3z4"
        out = ["3z4","3Z4"]
        self.assertEqual(sorted(Solution().letterCasePermutation(S)), sorted(out))
        S = "12345"
        out = ["12345"]
        self.assertEqual(sorted(Solution().letterCasePermutation(S)), sorted(out))
        S = "0"
        out = ["0"]
        self.assertEqual(sorted(Solution().letterCasePermutation(S)), sorted(out))
