import unittest
from typing import List
from collections import Counter


class Solution:
    def threeSumMulti(self, nums: List[int], target: int) -> int:
        cnts = Counter(nums)
        res = 0
        sorted_uniq_nums = sorted(cnts)
        for i, a in enumerate(sorted_uniq_nums):
            for j in range(i, len(sorted_uniq_nums)):
                b = sorted_uniq_nums[j]
                c = target - a - b
                if c >= b and cnts[c] > 0:
                    if a == b and b == c:
                        if cnts[b] >= 3:
                            res += cnts[b] * (cnts[b] - 1) * (cnts[b] - 2) // 6
                    elif a == b:
                        if cnts[b] >= 2:
                            res += cnts[c] * cnts[a] * (cnts[b] - 1) // 2
                    elif b == c:
                        if cnts[b] >= 2:
                            res += cnts[a] * cnts[b] * (cnts[c] - 1) // 2
                    else:
                        res += cnts[a] * cnts[b] * cnts[c]
        return res % (10 ** 9 + 7)


class Test(unittest.TestCase):
    def test(self):
        arr = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5]
        target = 8
        out = 20
        self.assertEqual(Solution().threeSumMulti(arr, target), out)
        arr = [1, 1, 2, 2, 2, 2]
        target = 5
        out = 12
        self.assertEqual(Solution().threeSumMulti(arr, target), out)
        arr = []
        target = 8
        out = 0
        self.assertEqual(Solution().threeSumMulti(arr, target), out)
        arr = [1]
        target = 8
        out = 0
        self.assertEqual(Solution().threeSumMulti(arr, target), out)
