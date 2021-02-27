import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def buildNode(nums, l, r):
            if l >= r:
                return None
            m = (l + r) // 2
            return TreeNode(nums[m], buildNode(nums, l, m), buildNode(nums, m + 1, r))

        return buildNode(nums, 0, len(nums))


class Test(unittest.TestCase):
    def test(self):
        nums = [-10, -3, 0, 5, 9]
        root = Solution().sortedArrayToBST(nums)
        self.assertEqual(root.val, 0)
        self.assertEqual(root.left.val, -3)
        self.assertEqual(root.right.val, 9)
