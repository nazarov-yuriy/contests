import unittest
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        node = head
        prev = None
        while node is not None:
            node.next, prev, node = prev, node, node.next
        return prev


class Test(unittest.TestCase):
    def test(self):
        head = ListNode(1, ListNode(2, ListNode(3)))
        rev = Solution().reverseList(head)
        self.assertEqual(
            [rev.val, rev.next.val, rev.next.next.val, rev.next.next.next],
            [3, 2, 1, None]
        )
        head = ListNode(1)
        rev = Solution().reverseList(head)
        self.assertEqual(
            [rev.val, rev.next],
            [1, None]
        )
        head = None
        rev = Solution().reverseList(head)
        self.assertEqual(
            [rev],
            [None]
        )
