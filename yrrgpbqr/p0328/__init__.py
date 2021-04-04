import unittest
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        odd_head = ListNode()
        even_head = ListNode()
        odd, even = odd_head, even_head
        pos = 1
        node = head
        while node:
            if pos % 2 == 1:
                odd.next = node
                odd = odd.next
            else:
                even.next = node
                even = even.next
            node = node.next
            pos += 1
        odd.next = even_head.next
        even.next = None
        return odd_head.next


class Test(unittest.TestCase):
    def test(self):
        head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
        Solution().oddEvenList(head)
        self.assertEqual(head.val, 1)
        self.assertEqual(head.next.val, 3)
        self.assertEqual(head.next.next.val, 5)
        self.assertEqual(head.next.next.next.val, 2)
        self.assertEqual(head.next.next.next.next.val, 4)
        self.assertEqual(head.next.next.next.next.next, None)
