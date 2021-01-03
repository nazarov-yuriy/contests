import unittest
from typing import List


class Solution:
    def reverseInplace(self, nums, l, r):  # including bounds
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1

    def nextPermutation(self, nums: List[int]) -> None:
        if len(nums) < 2:
            return nums
        for pos in range(len(nums) - 1, 0, -1):
            if nums[pos - 1] < nums[pos]:
                next_leading = nums[pos]
                next_leading_pos = pos
                for i in range(pos + 1, len(nums)):
                    if nums[pos - 1] < nums[i] and nums[i] <= next_leading:
                        next_leading = nums[i]
                        next_leading_pos = i
                nums[pos - 1], nums[next_leading_pos] = nums[next_leading_pos], nums[pos - 1]
                self.reverseInplace(nums, pos, len(nums) - 1)
                return
        # all nums are sorted desc
        self.reverseInplace(nums, 0, len(nums) - 1)


class Test(unittest.TestCase):
    def test(self):
        nums = [1,2,3]
        Solution().nextPermutation(nums)
        self.assertEqual(nums, [1,3,2])
        nums = [3,2,1]
        Solution().nextPermutation(nums)
        self.assertEqual(nums, [1,2,3])
        nums = [1,1,5]
        Solution().nextPermutation(nums)
        self.assertEqual(nums, [1,5,1])
        nums = [1]
        Solution().nextPermutation(nums)
        self.assertEqual(nums, [1])
        nums = [1,3,2]
        Solution().nextPermutation(nums)
        self.assertEqual(nums, [2,1,3])
        nums = [1,3,2,2]
        Solution().nextPermutation(nums)
        self.assertEqual(nums, [2,1,2,3])