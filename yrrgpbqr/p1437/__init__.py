import unittest
from typing import List


class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        dk = k + 1
        prev = -dk
        for i, num in enumerate(nums):
            if num == 1:
                if i - prev < dk:
                    return False
                prev = i
        return True


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 0, 0, 0, 1, 0, 0, 1]
        k = 2
        self.assertEqual(Solution().kLengthApart(nums, k), True)
        nums = [1, 0, 0, 1, 0, 1]
        k = 2
        self.assertEqual(Solution().kLengthApart(nums, k), False)
        nums = [1, 1, 1, 1, 1]
        k = 0
        self.assertEqual(Solution().kLengthApart(nums, k), True)
        nums = [0, 1, 0, 1]
        k = 1
        self.assertEqual(Solution().kLengthApart(nums, k), True)
