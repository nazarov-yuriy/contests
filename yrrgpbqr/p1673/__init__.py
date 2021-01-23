import unittest
from typing import List
import heapq


class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        left_pos = len(nums) - k + 1
        heap = [(num, i) for i, num in enumerate(nums[:left_pos])]
        heapq.heapify(heap)
        res = []
        prev_pos = 0
        while len(heap) > 0 and len(res) < k:
            candidate_num, candidate_pos = heapq.heappop(heap)
            if len(nums) - candidate_pos < k - len(res) or candidate_pos < prev_pos:
                continue
            res.append(candidate_num)
            prev_pos = candidate_pos
            if left_pos < len(nums):
                heapq.heappush(heap, (nums[left_pos], left_pos))
                left_pos += 1
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [3, 5, 2, 6]
        k = 2
        out = [2, 6]
        self.assertEqual(Solution().mostCompetitive(nums, k), out)
        nums = [2, 4, 3, 3, 5, 4, 9, 6]
        k = 4
        out = [2, 3, 3, 4]
        self.assertEqual(Solution().mostCompetitive(nums, k), out)
