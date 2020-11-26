import unittest
from typing import List


class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        queued_num = None
        queued_cnt = 0
        for i, num in enumerate(A):
            if i == len(A) - 1:
                break
            if queued_num is None:
                queued_num = num
                queued_cnt += 1
            elif queued_num == num:
                queued_cnt += 1
            else:
                queued_cnt -= 1
                if queued_cnt == 0:
                    queued_num = None
        if queued_cnt > 1:
            return queued_num
        else:
            last = A[-1]
            last_cnt = 0
            for num in A:
                if num == last:
                    last_cnt += 1
            if last_cnt == len(A) / 2:
                return last
            else:
                return queued_num


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            3,
            Solution().repeatedNTimes([1, 2, 3, 3])
        )
        self.assertEqual(
            1,
            Solution().repeatedNTimes([1, 2, 1, 3, 1, 4])
        )
        self.assertEqual(
            5,
            Solution().repeatedNTimes([5, 1, 5, 2, 5, 3, 5, 4])
        )
        self.assertEqual(
            2,
            Solution().repeatedNTimes([1, 2, 0, 2, 2, 2, 4, 8])
        )
