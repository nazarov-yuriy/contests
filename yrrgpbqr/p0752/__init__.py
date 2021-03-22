import unittest
from typing import List
import collections


class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)
        if "0000" in deadends:
            return -1
        graph = {}
        for a in range(10):
            for b in range(10):
                for c in range(10):
                    for d in range(10):
                        s = str(a) + str(b) + str(c) + str(d)
                        graph[s] = []
                        graph[s].append(str((a + 1) % 10) + str(b) + str(c) + str(d))
                        graph[s].append(str((a + 9) % 10) + str(b) + str(c) + str(d))
                        graph[s].append(str(a) + str((b + 1) % 10) + str(c) + str(d))
                        graph[s].append(str(a) + str((b + 9) % 10) + str(c) + str(d))
                        graph[s].append(str(a) + str(b) + str((c + 1) % 10) + str(d))
                        graph[s].append(str(a) + str(b) + str((c + 9) % 10) + str(d))
                        graph[s].append(str(a) + str(b) + str(c) + str((d + 1) % 10))
                        graph[s].append(str(a) + str(b) + str(c) + str((d + 9) % 10))
        queue = collections.deque()
        seen = set()
        queue.append(("0000", 0))
        seen.add("0000")
        while len(queue):
            code, steps = queue.popleft()
            if code == target:
                return steps
            for next in graph[code]:
                if next not in seen and next not in deadends:
                    queue.append((next, steps + 1))
                    seen.add(next)
        return -1


class Test(unittest.TestCase):
    def test(self):
        deadends = ["0201", "0101", "0102", "1212", "2002"]
        target = "0202"
        out = 6
        self.assertEqual(Solution().openLock(deadends, target), out)
        deadends = ["8888"]
        target = "0009"
        out = 1
        self.assertEqual(Solution().openLock(deadends, target), out)
        deadends = ["8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"]
        target = "8888"
        out = -1
        self.assertEqual(Solution().openLock(deadends, target), out)
        deadends = ["0000"]
        target = "8888"
        out = -1
        self.assertEqual(Solution().openLock(deadends, target), out)
