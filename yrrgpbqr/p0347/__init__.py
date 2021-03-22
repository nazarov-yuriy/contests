import unittest
from typing import List
import collections


# ToDo: use uniquiness of answer and implement bucket sort
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = collections.Counter(nums)
        return sorted(counts, key=lambda x: -counts[x])[:k]


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 1, 1, 2, 2, 3]
        k = 2
        out = [1, 2]
        self.assertEqual(Solution().topKFrequent(nums, k), out)
        nums = [1]
        k = 1
        out = [1]
        self.assertEqual(Solution().topKFrequent(nums, k), out)
