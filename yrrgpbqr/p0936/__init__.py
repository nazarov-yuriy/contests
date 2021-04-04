import unittest
from typing import List
import collections


class Solution:
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        state = list(target)
        offsets = len(target) - len(stamp) + 1
        todos = [0] * offsets
        blocks = [set() for _ in target]
        queue = collections.deque()
        for offset in range(offsets):
            for j, char in enumerate(stamp):
                if char != target[j + offset]:
                    todos[offset] += 1
                    blocks[j + offset].add(offset)
            if todos[offset] == 0:
                queue.append(offset)
        rev_res = []
        while len(queue) > 0:
            offset = queue.popleft()
            rev_res.append(offset)
            for j, char in enumerate(stamp):
                if state[offset + j] != '?':
                    state[offset + j] = '?'
                    for blocked_offset in blocks[offset + j]:
                        todos[blocked_offset] -= 1
                        if todos[blocked_offset] == 0:
                            queue.append(blocked_offset)
        if sum(todos) > 0:
            return []
        else:
            return list(reversed(rev_res))


class Test(unittest.TestCase):
    def test(self):
        stamp = "abc"
        target = "ababc"
        out = [1, 0, 2]
        self.assertEqual(Solution().movesToStamp(stamp, target), out)
        stamp = "abca"
        target = "aabcaca"
        out = [2, 3, 0, 1]
        self.assertEqual(Solution().movesToStamp(stamp, target), out)
