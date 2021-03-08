import unittest
from typing import List


class MyHashMap:
    def getHash(self, num):
        return (num * 17) % self.capacity

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.capacity = 10001
        self.buckets = [[] for _ in range(self.capacity)]

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        bucket = self.buckets[self.getHash(key)]
        for slot in bucket:
            if slot[0] == key:
                slot[1] = value
                return
        bucket.append([key, value])

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        bucket = self.buckets[self.getHash(key)]
        for slot in bucket:
            if slot[0] == key:
                return slot[1]
        return -1

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        bucket = self.buckets[self.getHash(key)]
        pos = None
        for i, slot in enumerate(bucket):
            if slot[0] == key:
                pos = i
        if pos is None:
            return
        if pos == len(bucket) - 1:
            bucket.pop()
        else:
            end = bucket.pop()
            bucket[pos] = end


class Test(unittest.TestCase):
    def test(self):
        hashMap = MyHashMap()
        hashMap.put(1, 1);
        hashMap.put(2, 2);
        self.assertEqual(hashMap.get(1), 1)
        self.assertEqual(hashMap.get(3), -1)
        hashMap.put(2, 1)
        self.assertEqual(hashMap.get(2), 1)
        hashMap.remove(2)
        self.assertEqual(hashMap.get(2), -1)
