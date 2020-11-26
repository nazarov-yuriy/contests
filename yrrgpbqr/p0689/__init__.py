import unittest
from typing import List


class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        sums = [0] * (len(nums) + 1)  # last = 0
        s = 0
        for i, num in enumerate(nums):
            s += num
            sums[i] = s

        max_sums1 = [0] * len(nums)
        max_pos1 = [-1] * len(nums)
        max_sums2 = [0] * len(nums)
        max_pos2 = [-1] * len(nums)
        max_sums3 = [0] * len(nums)
        max_pos3 = [-1] * len(nums)
        for i in range(k - 1, len(nums)):
            sum1 = sums[i] - sums[i - k]
            if sum1 > max_sums1[i - 1]:
                max_sums1[i] = sum1
                max_pos1[i] = i - k + 1
            else:
                max_sums1[i] = max_sums1[i - 1]
                max_pos1[i] = max_pos1[i - 1]
            if i >= 2 * k - 1:
                sum2 = sums[i] - sums[i - k] + max_sums1[i - k]
                if sum2 > max_sums2[i - 1]:
                    max_sums2[i] = sum2
                    max_pos2[i] = i - k + 1
                else:
                    max_sums2[i] = max_sums2[i - 1]
                    max_pos2[i] = max_pos2[i - 1]
            if i >= 3 * k - 1:
                sum3 = sums[i] - sums[i - k] + max_sums2[i - k]
                if sum3 > max_sums3[i - 1]:
                    max_sums3[i] = sum3
                    max_pos3[i] = i - k + 1
                else:
                    max_sums3[i] = max_sums3[i - 1]
                    max_pos3[i] = max_pos3[i - 1]
        return [
            max_pos1[max_pos2[max_pos3[-1] - 1] - 1],
            max_pos2[max_pos3[-1] - 1],
            max_pos3[-1],
        ]


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 2, 1, 2, 6, 7, 5, 1]
        k = 2
        self.assertEqual(
            [0, 3, 5],
            Solution().maxSumOfThreeSubarrays(nums, k)
        )
