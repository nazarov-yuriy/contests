import unittest
from typing import List
import collections


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        queue = collections.deque()
        seen = [False for _ in rooms]
        seen[0] = True
        queue.append(0)
        while len(queue) > 0:
            room = queue.popleft()
            for key in rooms[room]:
                if not seen[key]:
                    queue.append(key)
                    seen[key] = True
        return all(seen)


class Test(unittest.TestCase):
    def test(self):
        rooms = [[1], [2], [3], []]
        out = True
        self.assertEqual(Solution().canVisitAllRooms(rooms), out)
        rooms = [[1, 3], [3, 0, 1], [2], [0]]
        out = False
        self.assertEqual(Solution().canVisitAllRooms(rooms), out)
