import unittest
from typing import List


class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        consecutive = [nums[0]]
        res = True
        for num in nums[1:]:
            if num > consecutive[-1] + 1:
                res = self.isPossibleConsecutive(consecutive) and res
                consecutive = [num]
            else:
                consecutive.append(num)
        res = self.isPossibleConsecutive(consecutive) and res
        return res

    def isPossibleConsecutive(self, nums: List[int]) -> bool:
        prev_num = nums[0]
        prev_count = 0
        prev_prev_count = 0
        len1, len2, len3 = 0, 0, 0
        for num in nums + [None]:
            if num != prev_num:
                # print(prev_num, prev_count, len1, len2, len3)
                prev_num = num

                len3 -= max(0, prev_prev_count - prev_count)
                if len3 < 0:
                    return False
                len3 += len2
                len2 = len1
                len1 = max(0, prev_count - prev_prev_count)

                prev_prev_count = prev_count
                prev_count = 0
            prev_count += 1
        # print(len1, len2, len3)
        return len1 == 0 and len2 == 0


class Test(unittest.TestCase):
    def test_ensure_twos_complement(self):
        self.assertEqual(True, Solution().isPossible([1, 2, 2, 3, 3, 4, 5, 6, 7, 7, 8, 9]))
        self.assertEqual(True, Solution().isPossible([1, 2, 3, 3, 4, 5]))
        self.assertEqual(True, Solution().isPossible([1, 2, 3, 3, 4, 4, 5, 5]))
        self.assertEqual(False, Solution().isPossible([1, 2, 3, 4, 4, 5]))
        self.assertEqual(False, Solution().isPossible([1, 3, 3, 4, 4, 7, 8, 8, 9, 10]))
