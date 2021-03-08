import unittest
from typing import List


class TreeNode:
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right


class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, K: int) -> List[int]:
        res = []
        def inner(node, distance):
            if node is None:
                return
            if node is target:
                distance = K
                rev_distance = K
            else:
                rev_distance = None
            if distance is None:
                rev_left_distance = inner(node.left, None)
                rev_right_distance = inner(node.right, None)
                if rev_left_distance is not None:
                    rev_distance = rev_left_distance - 1
                    if rev_distance == 0:
                        res.append(node.val)
                    else:
                        inner(node.right, rev_distance - 1)
                elif rev_right_distance is not None:
                    rev_distance = rev_right_distance - 1
                    if rev_distance == 0:
                        res.append(node.val)
                    else:
                        inner(node.left, rev_distance - 1)
            else:
                if distance == 0:
                    res.append(node.val)
                inner(node.left, distance - 1)
                inner(node.right, distance - 1)
            return rev_distance

        inner(root, None)
        return res


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            3,
            TreeNode(5, TreeNode(6), TreeNode(2, TreeNode(7), TreeNode(4))),
            TreeNode(1, TreeNode(0), TreeNode(8))
        )
        K = 2
        out = [7,4,1]
        self.assertEqual(Solution().distanceK(root, root.left, K), out)
        root = TreeNode(
            3,
            TreeNode(5, TreeNode(6), TreeNode(2, TreeNode(7), TreeNode(4))),
            TreeNode(1, TreeNode(0), TreeNode(8))
        )
        K = 1
        out = [6, 2, 3]
        self.assertEqual(Solution().distanceK(root, root.left, K), out)
