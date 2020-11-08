import unittest


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __eq__(self, other):
        return type(self) == type(other) and self.val == other.val and self.next == other.next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        root = ListNode(0)
        curr = root
        carry = 0
        while l1 is not None or l2 is not None or carry != 0:
            s = (l1.val if l1 is not None else 0) + (l2.val if l2 is not None else 0) + carry
            carry = s // 10
            curr.next = ListNode(s % 10)
            curr = curr.next
            if l1 is not None:
                l1 = l1.next
            if l2 is not None:
                l2 = l2.next

        return root.next


class Test(unittest.TestCase):
    def test(self):
        l1 = ListNode(2, ListNode(4, ListNode(3)))
        l2 = ListNode(5, ListNode(6, ListNode(4)))
        res = ListNode(7, ListNode(0, ListNode(8)))
        self.assertEqual(Solution().addTwoNumbers(l1, l2), res)
        l1 = ListNode(0)
        l2 = ListNode(0)
        res = ListNode(0)
        self.assertEqual(Solution().addTwoNumbers(l1, l2), res)
        l1 = ListNode(1)
        l2 = ListNode(9, ListNode(9))
        res = ListNode(0, ListNode(0, ListNode(1)))
        self.assertEqual(Solution().addTwoNumbers(l1, l2), res)

