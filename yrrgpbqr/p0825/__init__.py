import unittest
from typing import List
from collections import Counter


class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        age_counter = Counter(ages)
        res = 0
        for age_a in age_counter:
            for age_b in age_counter:
                if age_b * 2 <= age_a + 14:  # age_b <= 0.5 * age_a + 7
                    continue
                if age_b > age_a:
                    continue
                if age_b > 100 and age_a < 100:  # ??? What the difference with age_b > age_a ?
                    continue
                if age_a == age_b:
                    res += age_counter[age_a] * age_counter[age_a] - age_counter[age_a]
                else:
                    res += age_counter[age_a] * age_counter[age_b]
        return res


class Test(unittest.TestCase):
    def test(self):
        ages = [16, 16]
        out = 2
        self.assertEqual(Solution().numFriendRequests(ages), out)
        ages = [16, 17, 18]
        out = 2
        self.assertEqual(Solution().numFriendRequests(ages), out)
        ages = [20, 30, 100, 110, 120]
        out = 3
        self.assertEqual(Solution().numFriendRequests(ages), out)
