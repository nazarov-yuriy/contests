import unittest
from typing import List
import heapq


class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        heap = []
        open = 0
        max_open = 0
        for interval in intervals:
            while len(heap) > 0 and heap[0] <= interval[0]:
                heapq.heappop(heap)
                open -= 1
            open += 1
            max_open = max(max_open, open)
            heapq.heappush(heap, interval[1])
        return max_open


class Test(unittest.TestCase):
    def test(self):
        intervals = [[0, 30], [5, 10], [15, 20]]
        out = 2
        self.assertEqual(Solution().minMeetingRooms(intervals), out)
        intervals = [[7, 10], [2, 4]]
        out = 1
        self.assertEqual(Solution().minMeetingRooms(intervals), out)
