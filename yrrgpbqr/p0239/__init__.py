import unittest
from typing import List
import collections


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue = collections.deque([(nums[0], 0)])
        res = [] if k > 1 else [nums[0]]
        for i in range(1, len(nums)):
            if i - queue[0][1] >= k:
                queue.popleft()
            while len(queue) and nums[i] >= queue[-1][0]:
                queue.pop()
            queue.append((nums[i], i))
            if i >= k - 1:
                res.append(queue[0][0])
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 3, -1, -3, 5, 3, 6, 7]
        k = 3
        out = [3, 3, 5, 5, 6, 7]
        self.assertEqual(Solution().maxSlidingWindow(nums, k), out)
        nums = [1, 2, 3]
        k = 1
        out = [1, 2, 3]
        self.assertEqual(Solution().maxSlidingWindow(nums, k), out)
        nums = [1, -1]
        k = 1
        out = [1, -1]
        self.assertEqual(Solution().maxSlidingWindow(nums, k), out)
