import unittest


class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        squares = []
        i = 1
        while i ** 2 <= n:
            squares.append(i ** 2)
            i += 1
        cache = [None] * (n + 1)
        cache[0] = False
        for i in range(1, n + 1):
            res = 0
            for j in squares:
                if i - j < 0:
                    break
                res = max(res, not cache[i - j])
                cache[i] = res
        return cache[n]


class Test(unittest.TestCase):
    def test(self):
        n = 1
        self.assertEqual(Solution().winnerSquareGame(n), True)
        n = 2
        self.assertEqual(Solution().winnerSquareGame(n), False)
        n = 4
        self.assertEqual(Solution().winnerSquareGame(n), True)
        n = 7
        self.assertEqual(Solution().winnerSquareGame(n), False)
