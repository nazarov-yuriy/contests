import unittest
from typing import List
import heapq


class Solution:
    def minOdd(self, n):
        while n & 1 == 0:
            n //= 2
        return n

    def minimumDeviation(self, nums: List[int]) -> int:
        nums_with_index = [(self.minOdd(n), i) for i, n in enumerate(nums)]
        max_num = max(nums_with_index)[0]
        heapq.heapify(nums_with_index)
        res = max_num
        while True:
            num, pos = heapq.heappop(nums_with_index)
            res = min(res, max_num - num)
            if nums[pos] % 2 == 0:
                if num >= nums[pos]:
                    break
            else:
                if num > nums[pos]:
                    break
            num *= 2
            max_num = max(max_num, num)
            heapq.heappush(nums_with_index, (num, pos))
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 2, 3, 4]
        out = 1
        self.assertEqual(Solution().minimumDeviation(nums), out)
        nums = [4, 1, 5, 20, 3]
        out = 3
        self.assertEqual(Solution().minimumDeviation(nums), out)
        nums = [2, 10, 8]
        out = 3
        self.assertEqual(Solution().minimumDeviation(nums), out)
