import unittest
from typing import List


class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        res = [0] * (n+1)
        stack = [-1]
        start = 0
        for i, event in enumerate(logs):
            func, action, time = event.split(":")
            func = int(func)
            time = int(time)
            if action == "start":
                res[stack[-1]] += time - start
                stack.append(func)
                start = time
            else:
                res[stack[-1]] += time + 1 - start
                stack.pop()
                start = time + 1
        return res[:-1]


class Test(unittest.TestCase):
    def test(self):
        n = 2
        logs = ["0:start:0", "1:start:2", "1:end:5", "0:end:6"]
        self.assertEqual(Solution().exclusiveTime(n , logs), [3, 4])
        n = 1
        logs = ["0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"]
        self.assertEqual(Solution().exclusiveTime(n, logs), [8])
        n = 2
        logs = ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
        self.assertEqual(Solution().exclusiveTime(n, logs), [7, 1])
        n = 2
        logs = ["0:start:0", "0:start:2", "0:end:5", "1:start:7", "1:end:7", "0:end:8"]
        self.assertEqual(Solution().exclusiveTime(n, logs), [8, 1])
        n = 1
        logs = ["0:start:0","0:end:0"]
        self.assertEqual(Solution().exclusiveTime(n, logs), [1])
