import unittest
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def getLen(self, node: ListNode) -> int:
        list_len = 0
        while node is not None:
            node = node.next
            list_len += 1
        return list_len

    def reverseList(self, head: ListNode) -> ListNode:
        node = head
        prev = None
        while node is not None:
            node.next, prev, node = prev, node, node.next
        return prev

    def isPalindrome(self, head: ListNode) -> bool:
        list_len = self.getLen(head)
        if list_len <= 1:
            return True
        node = head
        skip = (list_len + 1) // 2
        while skip > 0:
            node = node.next
            skip -= 1
        rev_head = self.reverseList(node)
        res = True
        l_node, r_node = head, rev_head
        while l_node is not None and r_node is not None:
            if l_node.val != r_node.val:
                res = False
            l_node = l_node.next
            r_node = r_node.next
        self.reverseList(rev_head)
        return res


class Test(unittest.TestCase):
    def test(self):
        head = ListNode(1, ListNode(2, ListNode(2, ListNode(1))))
        out = True
        self.assertEqual(Solution().isPalindrome(head), out)
        head = ListNode(1, ListNode(2, ListNode(2, ListNode(2))))
        out = False
        self.assertEqual(Solution().isPalindrome(head), out)
        head = ListNode(1, ListNode(2, ListNode(3, ListNode(1))))
        out = False
        self.assertEqual(Solution().isPalindrome(head), out)
        head = ListNode(1, ListNode(2, ListNode(2, ListNode(2, ListNode(1)))))
        out = True
        self.assertEqual(Solution().isPalindrome(head), out)
        head = ListNode(1, ListNode(2, ListNode(2, ListNode(3, ListNode(1)))))
        out = False
        self.assertEqual(Solution().isPalindrome(head), out)
