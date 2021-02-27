import unittest
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = None
        candidate_cnt = 0
        for num in nums:
            if candidate_cnt == 0:
                candidate_cnt = 1
                candidate = num
            else:
                if num == candidate:
                    candidate_cnt += 1
                else:
                    candidate_cnt -= 1
        return candidate


class Test(unittest.TestCase):
    def test(self):
        nums = [3, 2, 3]
        out = 3
        self.assertEqual(Solution().majorityElement(nums), out)
