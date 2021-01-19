import unittest
from typing import List
import collections


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return None
        copy_by_node = {}
        seen = {node}
        to_copy = collections.deque([node])
        while len(to_copy) > 0:
            old_node = to_copy.popleft()
            copy_by_node[old_node] = Node(old_node.val, old_node.neighbors)
            for neihbor in old_node.neighbors:
                if neihbor not in seen:
                    to_copy.append(neihbor)
                    seen.add(neihbor)
        for new_node in copy_by_node.values():
            new_node.neighbors = [copy_by_node[x] for x in new_node.neighbors]
        return copy_by_node[node]


class Test(unittest.TestCase):
    def test(self):
        nodes = [Node(1), Node(2), Node(3), Node(4)]
        nodes[0].neighbors = [nodes[1], nodes[3]]
        nodes[1].neighbors = [nodes[0], nodes[2]]
        nodes[2].neighbors = [nodes[1], nodes[3]]
        nodes[3].neighbors = [nodes[0], nodes[2]]
        clone = Solution().cloneGraph(nodes[0])
        self.assertEqual(clone.val, nodes[0].val)
        nodes = [Node(1)]
        clone = Solution().cloneGraph(nodes[0])
        self.assertEqual(clone.val, nodes[0].val)
