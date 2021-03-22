import unittest
from typing import List


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        negative_pos = -1
        positive_pos = 0
        while positive_pos < len(nums) and nums[positive_pos] <= 0:
            positive_pos += 1
            negative_pos += 1
        res = []
        while negative_pos >= 0 or positive_pos < len(nums):
            if negative_pos >= 0 and positive_pos < len(nums):
                if (nums[negative_pos] ** 2) < (nums[positive_pos] ** 2):
                    res.append(nums[negative_pos] ** 2)
                    negative_pos -= 1
                else:
                    res.append(nums[positive_pos] ** 2)
                    positive_pos += 1
            elif negative_pos >= 0:
                res.append(nums[negative_pos] ** 2)
                negative_pos -= 1
            else:
                res.append(nums[positive_pos] ** 2)
                positive_pos += 1
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [-4, -1, 0, 3, 10]
        out = [0, 1, 9, 16, 100]
        self.assertEqual(Solution().sortedSquares(nums), out)
