import unittest
from typing import List
import collections


class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        score = nums[0]
        queue = collections.deque([(score, 0)])
        for i in range(1, len(nums)):
            if i - queue[0][1] > k:
                queue.popleft()
            score = queue[0][0] + nums[i]
            while len(queue) and score >= queue[-1][0]:
                queue.pop()
            queue.append((score, i))
        return score


class Test(unittest.TestCase):
    def test(self):
        nums = [1, -1, -2, 4, -7, 3]
        k = 2
        out = 7
        self.assertEqual(Solution().maxResult(nums, k), out)
        nums = [10, -5, -2, 4, 0, 3]
        k = 3
        out = 17
        self.assertEqual(Solution().maxResult(nums, k), out)
        nums = [1, -5, -20, 4, -1, 3, -6, -3]
        k = 2
        out = 0
        self.assertEqual(Solution().maxResult(nums, k), out)
