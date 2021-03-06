import unittest
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"ListNode({self.val},{self.next})"


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        prehead = ListNode(0, head)
        node = prehead
        while node.next is not None:
            if node.next.next is not None and node.next.val == node.next.next.val:
                val = node.next.val
                while node.next is not None and node.next.val == val:
                    node.next = node.next.next
            else:
                node = node.next

        return prehead.next


class Test(unittest.TestCase):
    def test(self):
        head = ListNode(1, ListNode(2, ListNode(3, ListNode(3, ListNode(4, ListNode(4, ListNode(5)))))))
        res = Solution().deleteDuplicates(head)
        self.assertEqual(
            [res.val, res.next.val, res.next.next.val],
            [1, 2, 5]
        )
        head = ListNode(1, ListNode(1, ListNode(3, ListNode(3, ListNode(4, ListNode(4))))))
        res = Solution().deleteDuplicates(head)
        self.assertEqual(res, None)
