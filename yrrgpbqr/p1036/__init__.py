import unittest
from typing import List
import collections


class Solution:
    def isCellBlockedOrTargetReachable(self, cell, blocket_set, MAX_COORD, target):
        res = True
        queue = collections.deque()
        seen = set()
        sx, sy = cell
        tx, ty = target
        queue.append((sx, sy, 0))
        seen.add((sx, sy))
        while len(queue) > 0:
            x, y, distance = queue.popleft()
            if distance >= len(blocket_set):
                res = False
                break
            if x == tx and y == ty:
                res = False
                break
            for dx, dy in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < MAX_COORD and 0 <= ny < MAX_COORD and (nx, ny) not in blocket_set and (nx, ny) not in seen:
                    seen.add((nx, ny))
                    queue.append((nx, ny, distance + 1))
        return res

    def isEscapePossible(self, blocked, source, target):
        source = tuple(source)
        target = tuple(target)
        MAX_COORD = 1000000
        blocked_set = {(x, y) for x, y in blocked if (x, y) != source and (x, y) != target}

        return not (
                self.isCellBlockedOrTargetReachable(source, blocked_set, MAX_COORD, target)
                or self.isCellBlockedOrTargetReachable(target, blocked_set, MAX_COORD, source)
        )


class Test(unittest.TestCase):
    def test(self):
        blocked = [[0, 3], [1, 0], [1, 1], [1, 2], [1, 3]]
        source = [0, 0]
        target = [0, 2]
        out = True
        self.assertEqual(Solution().isEscapePossible(blocked, source, target), out)
        blocked = [[9, 1], [3, 4], [0, 8], [2, 6], [6, 0], [1, 0], [1, 3], [7, 9], [6, 6], [4, 4], [1, 5], [7, 6],
                   [6, 9], [1, 2], [4, 9], [5, 2], [9, 0], [6, 4], [7, 4], [0, 5], [8, 3], [5, 6], [4, 5], [2, 2],
                   [9, 8], [0, 9], [9, 6], [7, 2], [4, 3], [2, 0], [6, 2], [3, 5], [6, 5], [4, 7], [5, 9], [7, 8],
                   [2, 8], [4, 1], [0, 7], [9, 7], [4, 0], [5, 1], [9, 2], [2, 7], [2, 3]]
        blocked_set = {tuple(x) for x in blocked}
        source = [5, 2]
        target = [6, 2]
        out = True
        self.assertEqual(Solution().isEscapePossible(blocked, source, target), out)
