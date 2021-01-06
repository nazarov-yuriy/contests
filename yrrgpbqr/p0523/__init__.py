import unittest
from typing import List


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        if len(nums) < 2:
            return False
        if k == 0:
            for l, r in zip(nums[:-1], nums[1:]):
                if l ==0 and r == 0:
                    return True
            return False
        prefix_sum = [0]
        seen = set()
        for i, num in enumerate(nums):
            if i >= 1:
                seen.add(prefix_sum[i - 1])
            curr_sum = (prefix_sum[-1] + num) % k
            if curr_sum in seen:
                return True
            prefix_sum.append(curr_sum)
        return False


class Test(unittest.TestCase):
    def test(self):
        nums = [23, 2, 4, 6, 7]
        k = 6
        self.assertEqual(Solution().checkSubarraySum(nums, k), True)
        nums = [23, 2, 6, 4, 7]
        k = 6
        self.assertEqual(Solution().checkSubarraySum(nums, k), True)
        nums = [23, 2, 5, 5, 7]
        k = 8
        self.assertEqual(Solution().checkSubarraySum(nums, k), False)
        nums = [23, 2, 5, 5, 7]
        k = 8
        self.assertEqual(Solution().checkSubarraySum(nums, k), False)
        nums = [0, 1, 0, 2, 0]
        k = 0
        self.assertEqual(Solution().checkSubarraySum(nums, k), False)
        nums = [23, 2, 0, 0, 7]
        k = 0
        self.assertEqual(Solution().checkSubarraySum(nums, k), True)
