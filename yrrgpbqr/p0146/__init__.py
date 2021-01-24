import unittest
from typing import List

class Node:
    def __init__(self, val, next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev

class LRUCache:
    MAX_CAPACITY = 3000
    def __init__(self, capacity: int):
        self.pointers = [None] * self.MAX_CAPACITY
        queue = Node(None)  # other items has (key, value) in val
        queue.next = queue
        queue.prev = queue
        for _ in range(capacity):
            node = Node((self.MAX_CAPACITY, None), queue.next, queue)
            queue.next.prev, queue.next = node, node
        self.queue = queue

    def get(self, key: int) -> int:
        node = self.pointers[key]
        if node != None:
            node.next.prev, node.prev.next = node.prev, node.next
            node.next, node.prev = self.queue, self.queue.prev
            self.queue.prev.next, self.queue.prev = node, node
            return self.pointers[key].val[1]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        node = self.pointers[key]
        if node != None:
            node.next.prev, node.prev.next = node.prev, node.next
            node.next, node.prev = self.queue, self.queue.prev
            self.queue.prev.next, self.queue.prev = node, node
            node.val = (key, value)
        else:
            node = self.queue.next
            if node.val[0] < self.MAX_CAPACITY:
                self.pointers[node.val[0]] = None
            node.next.prev, node.prev.next = node.prev, node.next
            node.next, node.prev = self.queue, self.queue.prev
            self.queue.prev.next, self.queue.prev = node, node
            node.val = (key, value)
            self.pointers[key] = node


class Test(unittest.TestCase):
    def test(self):
        lRUCache = LRUCache(2)
        lRUCache.put(1, 1)
        lRUCache.put(2, 2)
        self.assertEqual(lRUCache.get(1), 1)
        lRUCache.put(3, 3);
        self.assertEqual(lRUCache.get(2), -1)
        lRUCache.put(4, 4);
        self.assertEqual(lRUCache.get(1), -1)
        self.assertEqual(lRUCache.get(3), 3)
        self.assertEqual(lRUCache.get(4), 4)
