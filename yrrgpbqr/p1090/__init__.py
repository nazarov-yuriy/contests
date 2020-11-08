import unittest
from typing import List


class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        values_by_label = {}
        for val, label in zip(values, labels):
            values_by_label.setdefault(label, []).append(val)
        largest_vals = []
        for label, values in values_by_label.items():
            largest_vals.extend(sorted(values, reverse=True)[:use_limit])
        return sum(sorted(largest_vals, reverse=True)[:num_wanted])

class Test(unittest.TestCase):
    def test(self):
        values = [5, 4, 3, 2, 1]
        labels = [1, 1, 2, 2, 3]
        num_wanted = 3
        use_limit = 1
        self.assertEqual(
            Solution().largestValsFromLabels(values, labels, num_wanted, use_limit),
            9
        )
        values = [5, 4, 3, 2, 1]
        labels = [1, 3, 3, 3, 2]
        num_wanted = 3
        use_limit = 2
        self.assertEqual(
            Solution().largestValsFromLabels(values, labels, num_wanted, use_limit),
            12
        )
        values = [9, 8, 8, 7, 6]
        labels = [0, 0, 0, 1, 1]
        num_wanted = 3
        use_limit = 1
        self.assertEqual(
            Solution().largestValsFromLabels(values, labels, num_wanted, use_limit),
            16
        )