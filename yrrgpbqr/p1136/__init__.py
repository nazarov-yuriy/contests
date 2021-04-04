import unittest
from typing import List


class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        prereqs = {}
        successors = {}
        for src, dst in relations:
            prereqs.setdefault(dst, set()).add(src)
            successors.setdefault(src, set()).add(dst)

        next_level = [x for x in range(1, n + 1) if len(prereqs.get(x, set())) == 0]
        levels = 0
        updated = True
        while updated:
            updated = False
            levels += 1
            level, next_level = next_level, []
            for course in level:
                for successor in successors.get(course, set()):
                    prereqs[successor].remove(course)
                    if len(prereqs[successor]) == 0:
                        next_level.append(successor)
                        updated = True
        if sum(len(x) for x in prereqs.values()) == 0:
            return levels
        else:
            return -1


class Test(unittest.TestCase):
    def test(self):
        n = 3
        relations = [[1, 3], [2, 3]]
        out = 2
        self.assertEqual(Solution().minimumSemesters(n, relations), out)
        n = 3
        relations = [[1, 2], [2, 3], [3, 1]]
        out = -1
        self.assertEqual(Solution().minimumSemesters(n, relations), out)
