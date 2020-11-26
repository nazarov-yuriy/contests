import unittest
from typing import List
from collections import namedtuple


class Solution:
    BRICK_END = 0
    BRICK_START = 1

    def leastBricks(self, wall: List[List[int]]) -> int:
        Event = namedtuple('Event', ['position', 'event_type'])
        queue = []
        for row in wall:
            brick_offset = 0
            for i, brick_width in enumerate(row):
                if i != 0:
                    queue.append(Event(brick_offset, self.BRICK_START))
                if i != len(row) - 1:
                    queue.append(Event(brick_offset + brick_width, self.BRICK_END))
                brick_offset += brick_width
        crosses = len(wall)
        min_crosses = crosses
        for event in sorted(queue):
            if event.event_type == self.BRICK_END:
                crosses -= 1
            elif event.event_type == self.BRICK_START:
                crosses += 1
            else:
                assert False
            min_crosses = min(min_crosses, crosses)
        return min_crosses


class Test(unittest.TestCase):
    def test(self):
        wall = [
            [1, 2, 2, 1],
            [3, 1, 2],
            [1, 3, 2],
            [2, 4],
            [3, 1, 2],
            [1, 3, 1, 1]
        ]
        self.assertEqual(2, Solution().leastBricks(wall))
        wall = [
            [1],
            [1],
            [1],
        ]
        self.assertEqual(3, Solution().leastBricks(wall))
