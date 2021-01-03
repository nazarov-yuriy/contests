import unittest


class TreeNode:
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right


class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        if original is target:
            return cloned
        if original.left:
            left_res = self.getTargetCopy(original.left, cloned.left, target)
            if left_res is not None:
                return left_res
        if original.right:
            right_res = self.getTargetCopy(original.right, cloned.right, target)
            if right_res is not None:
                return right_res
        return None


class Test(unittest.TestCase):
    def test(self):
        original = TreeNode(
            7,
            TreeNode(4),
            TreeNode(
                3,
                TreeNode(6),
                TreeNode(19)
            )
        )
        copy = TreeNode(
            7,
            TreeNode(4),
            TreeNode(
                3,
                TreeNode(6),
                TreeNode(19)
            )
        )
        self.assertEqual(Solution().getTargetCopy(original, copy, original.right), copy.right)
