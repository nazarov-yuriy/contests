import unittest
from typing import List
import sys

sys.setrecursionlimit(10009)


class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        max_num = max(nums)
        counts = [0] * (max_num + 1)
        for num in nums:
            counts[num] += 1
        res_sequential = [[None] * (max_num + 1) for _ in range(max_num + 1)]

        def deleteAndEarnSequential(l, r):
            if l > r:
                return 0
            if l == r:
                return l * counts[l]
            if res_sequential[l][r] is None:
                res_sequential[l][r] = max(
                    l * counts[l] + deleteAndEarnSequential(l + 2, r),
                    (l + 1) * counts[l + 1] + deleteAndEarnSequential(l + 3, r),
                )
            return res_sequential[l][r]

        res = 0
        state = 0
        sequential_l = 0
        for i in range(max_num + 1):
            if state == 0:
                if counts[i] > 0:
                    sequential_l = i
                    state = 1
            if state == 1:
                if i == max_num or counts[i + 1] == 0:
                    res += deleteAndEarnSequential(sequential_l, i)
                    state = 0

        return res


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            Solution().deleteAndEarn([1]),
            1
        )
        self.assertEqual(
            Solution().deleteAndEarn([3, 4, 2]),
            6
        )
        self.assertEqual(
            Solution().deleteAndEarn([2, 2, 3, 3, 3, 4]),
            9
        )
        self.assertEqual(
            Solution().deleteAndEarn(list(range(1, 10001)) + list(range(1, 10001))),
            50010000
        )
