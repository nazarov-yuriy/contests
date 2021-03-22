import unittest
from typing import List
import heapq


class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        heap = []
        positions = [1] * len(mat)
        for i, seq in enumerate(mat):
            heapq.heappush(heap, (seq[0], i))
        prev = 0
        prev_cnt = 0
        while len(heap) > 0:
            el, seq_id = heapq.heappop(heap)
            if prev == el:
                if prev_cnt == seq_id:
                    prev_cnt += 1
            else:
                if prev_cnt == len(mat):
                    return prev
                prev = el
                prev_cnt = 1
            if positions[seq_id] < len(mat[seq_id]):
                heapq.heappush(heap, (mat[seq_id][positions[seq_id]], seq_id))
                positions[seq_id] += 1
        if prev_cnt == len(mat):
            return prev
        else:
            return -1


class Test(unittest.TestCase):
    def test(self):
        mat = [[1, 2, 3, 4, 5], [2, 4, 5, 8, 10], [3, 5, 7, 9, 11], [1, 3, 5, 7, 9]]
        out = 5
        self.assertEqual(Solution().smallestCommonElement(mat), out)
