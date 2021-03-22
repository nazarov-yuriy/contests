import unittest
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        step = 1
        prehead = ListNode(0, head)
        while True:
            start = prehead
            merged = 0
            while start.next is not None:
                l = start.next
                l_left = step
                r = start.next
                r_left = step
                pos = 0
                while pos < step and r is not None:
                    r = r.next
                    pos += 1
                if r is None:
                    start.next = l
                    break
                merged += 1
                last_r_next = r.next
                while (l is not None and l_left > 0) and (r is not None and r_left > 0):
                    if l.val < r.val:
                        start.next = l
                        l = l.next
                        l_left -= 1
                    else:
                        start.next = r
                        last_r_next = r.next
                        r = r.next
                        r_left -= 1
                    start = start.next
                while l is not None and l_left > 0:
                    start.next = l
                    l = l.next
                    l_left -= 1
                    start = start.next
                while r is not None and r_left > 0:
                    start.next = r
                    last_r_next = r.next
                    r = r.next
                    r_left -= 1
                    start = start.next
                start.next = last_r_next
            if merged == 0:
                break
            step *= 2
        return prehead.next


class Test(unittest.TestCase):
    def test(self):
        head = ListNode(4, ListNode(2, ListNode(1, ListNode(3))))
        res = Solution().sortList(head)
        self.assertEqual(res.val, 1)
        self.assertEqual(res.next.val, 2)
        self.assertEqual(res.next.next.val, 3)
        self.assertEqual(res.next.next.next.val, 4)
        self.assertEqual(res.next.next.next.next, None)
