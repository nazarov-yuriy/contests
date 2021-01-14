import unittest
from typing import List


class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        prefix_sums = [0]
        for num in nums:
            prefix_sums.append(prefix_sums[-1] + num)
        first_pos = {}
        for i, ps in enumerate(prefix_sums):
            if ps not in first_pos:
                first_pos[ps] = i
        suffix_sum = 0
        res = len(nums) + 1
        for i in range(len(nums) - 1, -1, -1):
            j = len(nums) - 1 - i
            if x - suffix_sum in first_pos:
                res = min(res, j + first_pos[x - suffix_sum])
            suffix_sum += nums[i]
        return res if res <= len(nums) else -1


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 1, 4, 2, 3]
        x = 5
        self.assertEqual(Solution().minOperations(nums, x), 2)
        nums = [5, 6, 7, 8, 9]
        x = 4
        self.assertEqual(Solution().minOperations(nums, x), -1)
        nums = [3, 2, 20, 1, 1, 3]
        x = 10
        self.assertEqual(Solution().minOperations(nums, x), 5)
