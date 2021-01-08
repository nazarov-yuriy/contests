import unittest
from typing import List


class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next


class Solution:
    def insert(self, head: 'Node', insertVal: int) -> 'Node':
        new_node = Node(insertVal)
        if head is None:
            new_node.next = new_node
            return new_node
        max_node = head
        while max_node.next.val >= max_node.val and max_node.next != head:
            max_node = max_node.next
        node = max_node
        while True:
            if new_node.val <= node.next.val:
                new_node.next = node.next
                node.next = new_node
                break
            else:
                node = node.next
                if node == max_node:  # full circle
                    new_node.next = node.next
                    node.next = new_node
                    break
        return head


class Test(unittest.TestCase):
    def test(self):
        head = Node(3)
        head.next = Node(4, Node(1, head))
        Solution().insert(head, 2)
        self.assertEqual(
            [head.val, head.next.val, head.next.next.val, head.next.next.next.val, head.next.next.next.next.val],
            [3, 4, 1, 2, 3]
        )
        head = Node(3)
        head.next = Node(4, Node(1, head))
        Solution().insert(head, 0)
        self.assertEqual(
            [head.val, head.next.val, head.next.next.val, head.next.next.next.val, head.next.next.next.next.val],
            [3, 4, 0, 1, 3]
        )
        head = Node(3)
        head.next = Node(4, Node(1, head))
        Solution().insert(head, 5)
        self.assertEqual(
            [head.val, head.next.val, head.next.next.val, head.next.next.next.val, head.next.next.next.next.val],
            [3, 4, 5, 1, 3]
        )
        head = Node(1)
        head.next = Node(1, Node(1, head))
        Solution().insert(head, 2)
        self.assertEqual(
            [head.val, head.next.val, head.next.next.val, head.next.next.next.val, head.next.next.next.next.val],
            [1, 1, 1, 2, 1]
        )
