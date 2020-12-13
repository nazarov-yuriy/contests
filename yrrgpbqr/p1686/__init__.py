import unittest
from typing import List


class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        values = sorted([(a + b, a, b) for a, b in zip(aliceValues, bobValues)], reverse=True)
        alice_score = sum(x[1] for x in values[0::2])
        bob_score = sum(x[2] for x in values[1::2])
        if alice_score == bob_score:
            return 0
        elif alice_score > bob_score:
            return 1
        else:
            return -1


class Test(unittest.TestCase):
    def test(self):
        aliceValues = [1, 3]
        bobValues = [2, 1]
        self.assertEqual(Solution().stoneGameVI(aliceValues, bobValues), 1)
        aliceValues = [1, 2]
        bobValues = [3, 1]
        self.assertEqual(Solution().stoneGameVI(aliceValues, bobValues), 0)
        aliceValues = [2, 4, 3]
        bobValues = [1, 6, 7]
        self.assertEqual(Solution().stoneGameVI(aliceValues, bobValues), -1)
