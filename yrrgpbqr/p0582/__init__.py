import unittest
from typing import List
from collections import deque


class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        children = {}
        for child, parent in zip(pid, ppid):
            children.setdefault(parent, set()).add(child)
        queue = deque([kill])
        seen = {kill}
        while len(queue) > 0:
            parent = queue.popleft()
            for child in children.get(parent, set()):
                if child not in seen:
                    seen.add(child)
                    queue.append(child)
        return list(seen)


class Test(unittest.TestCase):
    def test(self):
        pid = [1, 3, 10, 5]
        ppid = [3, 0, 5, 3]
        kill = 5
        out = [5, 10]
        self.assertEqual(sorted(Solution().killProcess(pid, ppid, kill)), out)
