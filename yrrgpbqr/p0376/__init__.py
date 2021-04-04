import unittest
from typing import List


class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        nums_without_repeats = []
        prev = None
        for num in nums:
            if num != prev:
                nums_without_repeats.append(num)
                prev = num
        nums = nums_without_repeats

        lens = [[0] * len(nums) for _ in range(len(nums) + 2)]
        res = 0
        for seq_len in range(1, len(nums) + 1):
            for i in range(len(nums) - seq_len + 1):
                if seq_len == 1:
                    lens[seq_len][i] = 1
                elif seq_len == 2:
                    if nums[i] < nums[i + 1]:
                        lens[seq_len][i] = 2
                    else:
                        lens[seq_len][i] = -2
                else:
                    if nums[i] < nums[i + 1]:
                        if lens[seq_len - 1][i + 1] < 0:
                            lens[seq_len][i] = 1 - lens[seq_len - 1][i + 1]
                        else:
                            lens[seq_len][i] = lens[seq_len - 1][i + 1]
                    else:
                        if lens[seq_len - 1][i + 1] > 0:
                            lens[seq_len][i] = - 1 - lens[seq_len - 1][i + 1]
                        else:
                            lens[seq_len][i] = lens[seq_len - 1][i + 1]
            res = max(res, max(lens[seq_len]), -min(lens[seq_len]))
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 7, 4, 9, 2, 5]
        out = 6
        self.assertEqual(Solution().wiggleMaxLength(nums), out)
        nums = [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
        out = 7
        self.assertEqual(Solution().wiggleMaxLength(nums), out)
        nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        out = 2
        self.assertEqual(Solution().wiggleMaxLength(nums), out)
