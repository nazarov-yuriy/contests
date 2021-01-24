import unittest
from typing import List
import heapq


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __lt__(self, other):
        return self.val < other.val


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        head = ListNode()
        tail = head
        heap = [(node.val, uniq_id, node) for uniq_id, node in enumerate(lists) if node is not None]
        uniq_id = len(lists)
        heapq.heapify(heap)
        while len(heap) > 0:
            _, _, node = heapq.heappop(heap)
            if node.next is not None:
                heapq.heappush(heap, (node.next.val, uniq_id, node.next))
                uniq_id += 1
            tail.next, tail = node, node
        return head.next

    def compactMergeKLists(self, lists: List[ListNode]) -> ListNode:
        head = ListNode()
        tail = head
        heap = [node for node in lists if node is not None]
        heapq.heapify(heap)
        while len(heap) > 0:
            node = heapq.heappop(heap)
            if node.next is not None:
                heapq.heappush(heap, node.next)
            tail.next, tail = node, node
        return head.next


class Test(unittest.TestCase):
    def test(self):
        lists = [
            ListNode(1, ListNode(4, ListNode(5))),
            ListNode(1, ListNode(3, ListNode(4))),
            ListNode(2, ListNode(6)),
        ]
        merged = Solution().mergeKLists(lists)
        self.assertEqual(merged.val, 1)
        self.assertEqual(merged.next.val, 1)
        self.assertEqual(merged.next.next.val, 2)
        self.assertEqual(merged.next.next.next.val, 3)
        self.assertEqual(merged.next.next.next.next.val, 4)
        self.assertEqual(merged.next.next.next.next.next.val, 4)
        self.assertEqual(merged.next.next.next.next.next.next.val, 5)
        self.assertEqual(merged.next.next.next.next.next.next.next.val, 6)

        lists = [
            ListNode(1, ListNode(4, ListNode(5))),
            ListNode(1, ListNode(3, ListNode(4))),
            ListNode(2, ListNode(6)),
        ]
        merged = Solution().compactMergeKLists(lists)
        self.assertEqual(merged.val, 1)
        self.assertEqual(merged.next.val, 1)
        self.assertEqual(merged.next.next.val, 2)
        self.assertEqual(merged.next.next.next.val, 3)
        self.assertEqual(merged.next.next.next.next.val, 4)
        self.assertEqual(merged.next.next.next.next.next.val, 4)
        self.assertEqual(merged.next.next.next.next.next.next.val, 5)
        self.assertEqual(merged.next.next.next.next.next.next.next.val, 6)
