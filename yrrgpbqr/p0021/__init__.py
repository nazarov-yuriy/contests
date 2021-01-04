import unittest
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        root = ListNode()
        node = root
        while l1 is not None and l2 is not None:
            if l1.val <= l2.val:
                node.next = l1
                node = l1
                l1 = l1.next
            else:
                node.next = l2
                node = l2
                l2 = l2.next
        node.next = l1 or l2
        return root.next


class Test(unittest.TestCase):
    def test(self):
        a2 = ListNode(4)
        a1 = ListNode(2, a2)
        a0 = ListNode(1, a1)
        b2 = ListNode(4)
        b1 = ListNode(3, b2)
        b0 = ListNode(1, b1)
        res = Solution().mergeTwoLists(a0, b0)
        assert res is a0
        res = res.next
        assert res is b0
        res = res.next
        assert res is a1
        res = res.next
        assert res is b1
        res = res.next
        assert res is a2
        res = res.next
        assert res is b2
