import unittest
from typing import List
from collections import Counter
import heapq


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        if n == 0:
            return len(tasks)
        c = Counter(tasks)
        heap = [(-v, k) for k, v in c.items()]
        heapq.heapify(heap)
        res = []
        while len(heap) > 0:
            uniq_tasks = []
            for _ in range(min(n+1, len(heap))):
                uniq_tasks.append(heapq.heappop(heap))
            for task in uniq_tasks:
                if task[0]+1 < 0:
                    heapq.heappush(heap, (task[0]+1, task[1]))
            res.extend([task[1] for task in uniq_tasks] + ["idle"]*(n+1-len(uniq_tasks)))
        while len(res) > 0 and res[-1] == "idle":
            res.pop()
        return len(res)


class Test(unittest.TestCase):
    def test(self):
        tasks = ["A", "A", "A", "B", "B", "B"]
        n = 2
        self.assertEqual(Solution().leastInterval(tasks, n), 8)
        tasks = ["A", "A", "A", "B", "B", "B"]
        n = 0
        self.assertEqual(Solution().leastInterval(tasks, n), 6)
        tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"]
        n = 2
        self.assertEqual(Solution().leastInterval(tasks, n), 16)
