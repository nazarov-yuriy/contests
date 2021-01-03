import unittest
from itertools import chain, product


class Solution:
    def countArrangement(self, n: int) -> int:
        positions = [
            [i for i in range(1, n + 1) if ((i % num == 0) or (num % i == 0))]
            for num in range(1, n + 1)
        ]
        answers = {
            (x,): {x} for x in positions[0]
        }
        for p in positions[1:]:
            answers_next = {}
            for num in p:
                for k, v in answers.items():
                    if num not in v:
                        answers_next[tuple(k + (num,))] = set(k + (num,))
            answers = answers_next
        return len(answers)


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().countArrangement(1), 1)
        self.assertEqual(Solution().countArrangement(2), 2)
        self.assertEqual(Solution().countArrangement(3), 3)
        self.assertEqual(Solution().countArrangement(10), 700)
        self.assertEqual(Solution().countArrangement(11), 750)
        self.assertEqual(Solution().countArrangement(12), 4010)
        self.assertEqual(Solution().countArrangement(13), 4237)
        self.assertEqual(Solution().countArrangement(14), 10680)
        self.assertEqual(Solution().countArrangement(15), 24679)