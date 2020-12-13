import unittest


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __eq__(self, other):
        if other is None:
            return 0
        return self.val == other.val and self.left == other.left and self.right == other.right


class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        def inner(node):
            end = node
            orig_right = node.right
            if node.left:
                end = inner(node.left)
                end.right = node.right
                node.right, node.left = node.left, None
            if orig_right:
                end = inner(orig_right)
            return end

        if root:
            inner(root)


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            1,
            TreeNode(2),
            TreeNode(5)
        )
        flat = TreeNode(
            1,
            None,
            TreeNode(
                2,
                None,
                TreeNode(5)
            )
        )
        Solution().flatten(root)
        self.assertEqual(
            root,
            flat
        )
