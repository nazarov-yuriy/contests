import unittest
from typing import List


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        sorted_nums = sorted(people)
        l, r = 0, len(people) - 1
        res = 0
        while l <= r:
            if sorted_nums[l] + sorted_nums[r] <= limit:
                l += 1
            r -= 1
            res += 1
        return res


class Test(unittest.TestCase):
    def test(self):
        people = [1, 2]
        limit = 3
        self.assertEqual(Solution().numRescueBoats(people, limit), 1)
        people = [3, 2, 2, 1]
        limit = 3
        self.assertEqual(Solution().numRescueBoats(people, limit), 3)
        people = [3, 5, 3, 4]
        limit = 5
        self.assertEqual(Solution().numRescueBoats(people, limit), 4)
