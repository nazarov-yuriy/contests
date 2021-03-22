import unittest
from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        MAX_T = target
        candidates = sorted(candidates, reverse=True)
        possible = [[False] * (MAX_T + 1) for _ in candidates]
        use = [[False] * (MAX_T + 1) for _ in candidates]

        for i, candidate in enumerate(candidates):
            possible[i][0] = True
            for j in range((MAX_T + 1)):
                if j - candidate >= 0:
                    if possible[i][j - candidate]:
                        use[i][j] = True
                        possible[i][j] = True
                if i > 0 and possible[i - 1][j]:
                    possible[i][j] = True
        res = []
        stack = []

        def walk(pos, val):
            if val == 0:
                res.append(list(stack))
            elif val > 0 and pos >= 0:
                if use[pos][val]:
                    stack.append(candidates[pos])
                    walk(pos, val - candidates[pos])
                    stack.pop()
                walk(pos - 1, val)

        walk(len(candidates) - 1, target)
        return res


class Test(unittest.TestCase):
    def test(self):
        candidates = [2, 3, 6, 7]
        target = 7
        out = [[2, 2, 3], [7]]
        self.assertEqual(sorted(Solution().combinationSum(candidates, target)), out)
        candidates = [2, 3, 5]
        target = 8
        out = [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
        self.assertEqual(sorted(Solution().combinationSum(candidates, target)), out)
        candidates = [2, 7, 6, 3, 5, 1]
        target = 9
        out = [[1, 1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1, 2], [1, 1, 1, 1, 1, 1, 3], [1, 1, 1, 1, 1, 2, 2],
               [1, 1, 1, 1, 2, 3], [1, 1, 1, 1, 5], [1, 1, 1, 2, 2, 2], [1, 1, 1, 3, 3], [1, 1, 1, 6], [1, 1, 2, 2, 3],
               [1, 1, 2, 5], [1, 1, 7], [1, 2, 2, 2, 2], [1, 2, 3, 3], [1, 2, 6], [1, 3, 5], [2, 2, 2, 3], [2, 2, 5],
               [2, 7], [3, 3, 3], [3, 6]]
        self.assertEqual(sorted(Solution().combinationSum(candidates, target)), out)
        candidates = [2]
        target = 1
        out = []
        self.assertEqual(sorted(Solution().combinationSum(candidates, target)), out)
