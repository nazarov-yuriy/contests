import unittest
from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        for i in range(2 ** len(nums)):
            local_res = []
            for j, num in enumerate(nums):
                if i & (1 << j):
                    local_res.append(num)
            res.append(local_res)
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 2, 3]
        out = [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
        self.assertEqual(sorted(Solution().subsets(nums)), sorted(out))
