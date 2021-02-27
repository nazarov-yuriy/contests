import unittest
from typing import List


class ListNode:
    def __init__(self, x, next=None):
        self.val = x
        self.next = next


class Solution:
    def getLen(self, node):
        list_len = 0
        while node is not None:
            node = node.next
            list_len += 1
        return list_len

    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        len_a = self.getLen(headA)
        len_b = self.getLen(headB)
        while len_a > len_b:
            headA = headA.next
            len_a -= 1
        while len_a < len_b:
            headB = headB.next
            len_b -= 1
        while headA is not None and headB is not None:
            if headA is headB:
                return headA
            headA = headA.next
            headB = headB.next
        return None


class Test(unittest.TestCase):
    def test(self):
        headA = ListNode(1, ListNode(2, ListNode(3)))
        headB = ListNode(4, headA.next.next)
        self.assertEqual(Solution().getIntersectionNode(headA, headB), headB.next)
        headA = ListNode(1, ListNode(2, ListNode(3)))
        headB = ListNode(4, ListNode(5))
        self.assertEqual(Solution().getIntersectionNode(headA, headB), None)
