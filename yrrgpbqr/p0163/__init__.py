import unittest
from typing import List


class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        if len(nums) == 0 or nums[0] != lower:
            nums = [lower - 1] + nums
        if nums[-1] != upper:
            nums += [upper + 1]
        if len(nums) < 2:
            return []
        res = []
        for l, r in zip(nums[:-1], nums[1:]):
            if r - l == 1:
                continue
            elif r - l == 2:
                res.append(str(l + 1))
            else:
                res.append(str(l + 1) + "->" + str(r - 1))
        return res


class Test(unittest.TestCase):
    def test(self):
        nums = [0, 1, 3, 50, 75]
        lower = 0
        upper = 99
        out = ["2", "4->49", "51->74", "76->99"]
        self.assertEqual(Solution().findMissingRanges(nums, lower, upper), out)
        nums = []
        lower = 1
        upper = 1
        out = ["1"]
        self.assertEqual(Solution().findMissingRanges(nums, lower, upper), out)
        nums = []
        lower = -3
        upper = -1
        out = ["-3->-1"]
        self.assertEqual(Solution().findMissingRanges(nums, lower, upper), out)
