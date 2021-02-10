import unittest
from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None:
            return False
        to_skip = 1
        distance = to_skip
        seen = head
        while head.next:
            head = head.next
            if head == seen:
                return True
            distance -= 1
            if distance == 0:
                seen = head
                to_skip *= 2
                distance = to_skip
        return False


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(1, 1)
