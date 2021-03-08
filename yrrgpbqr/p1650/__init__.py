import unittest
from typing import List


class Solution:
    def getDepth(self, node):
        depth = 0
        while node:
            depth += 1
            node = node.parent
        return depth

    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        # get depth
        depth_p = self.getDepth(p)
        depth_q = self.getDepth(q)
        # lca
        while depth_q > depth_p:
            q = q.parent
            depth_q -= 1
        while depth_p > depth_q:
            p = p.parent
            depth_p -= 1
        while p and q:
            if p is q:
                return p
            p = p.parent
            q = q.parent
        return None  # Different trees)


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(1, 1)
