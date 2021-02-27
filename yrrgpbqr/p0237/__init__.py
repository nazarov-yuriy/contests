import unittest
from typing import List


class ListNode:
    def __init__(self, x, next=None):
        self.val = x
        self.next = next


class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next


class Test(unittest.TestCase):
    def test(self):
        head = ListNode(4, ListNode(5, ListNode(1, ListNode(9))))
        Solution().deleteNode(head.next)
        self.assertEqual(
            [head.val, head.next.val, head.next.next.val, head.next.next.next],
            [4, 1, 9, None]
        )
