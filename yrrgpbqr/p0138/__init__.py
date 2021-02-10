import unittest
from typing import List


class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        copy_node = Node(0)
        orig_node = head
        old2new = {}
        while orig_node:
            old2new[orig_node] = Node(orig_node.val)
            copy_node.next = old2new[orig_node]
            copy_node = copy_node.next
            orig_node = orig_node.next
        orig_node = head
        copy_node = old2new.get(head)
        while orig_node:
            copy_node.random = old2new.get(orig_node.random)
            copy_node = copy_node.next
            orig_node = orig_node.next
        return old2new.get(head)


class Test(unittest.TestCase):
    def test(self):
        new_head = Solution().copyRandomList(None)
        self.assertEqual(new_head, None)
