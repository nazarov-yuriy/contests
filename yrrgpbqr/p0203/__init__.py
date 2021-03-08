import unittest
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        fake = ListNode(0, head)
        node = fake
        while node is not None:
            while node.next is not None and node.next.val == val:
                node.next = node.next.next
            node = node.next
        return fake.next


class Test(unittest.TestCase):
    def test(self):
        head = ListNode(1,ListNode(2,ListNode(6,ListNode(3,ListNode(4,ListNode(5,ListNode(6)))))))
        new_head = Solution().removeElements(head, 6)
        self.assertEqual(new_head.val, 1)
        self.assertEqual(new_head.next.val, 2)
        self.assertEqual(new_head.next.next.val, 3)
        self.assertEqual(new_head.next.next.next.val, 4)
        self.assertEqual(new_head.next.next.next.next.val, 5)
        self.assertEqual(new_head.next.next.next.next.next, None)
        head = None
        new_head = Solution().removeElements(head, 6)
