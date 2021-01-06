import unittest
from typing import List
from itertools import product


class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        if len(num) <= 1:
            return []
        res = []
        operator_lists = [["+", "-", "*", ""]] * (len(num) - 1)
        for operators in product(*operator_lists):
            expr = "".join([d + o for d, o in zip(num[:-1], operators)]) + num[-1]
            if expr.startswith("00") or "+00" in expr or "-00" in expr or "*00" in expr:
                continue
            try:
                if eval(expr) == target:
                    res.append(expr)
            except SyntaxError:
                pass
        return res


class Test(unittest.TestCase):
    def test(self):
        num = "123"
        target = 6
        self.assertEqual(Solution().addOperators(num, target), ["1+2+3", "1*2*3"])
        num = "232"
        target = 8
        self.assertEqual(Solution().addOperators(num, target), ["2+3*2", "2*3+2"])
        num = "105"
        target = 5
        self.assertEqual(Solution().addOperators(num, target), ["1*0+5", "10-5"])
        num = "00"
        target = 0
        self.assertEqual(Solution().addOperators(num, target), ["0+0", "0-0", "0*0"])
        num = "3456237490"
        target = 9191
        self.assertEqual(Solution().addOperators(num, target), [])
        num = "000"
        target = 0
        self.assertEqual(
            sorted(Solution().addOperators(num, target)),
            sorted(["0*0*0", "0*0+0", "0*0-0", "0+0*0", "0+0+0", "0+0-0", "0-0*0", "0-0+0", "0-0-0"])
        )
        num = "2147483647"
        target = 2147483647
        self.assertEqual(
            sorted(Solution().addOperators(num, target)),
            sorted(["2147483647"])
        )
