import unittest
from typing import List
from textwrap import indent


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        v = indent(f"{self.val}", "    ")
        l = indent(repr(self.left), "    ")
        r = indent(repr(self.right), "    ")
        return f"TreeNode(\n{v},\n{l},\n{r}\n)"


class Codec:
    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        res = []

        def walk(node):
            if node is None:
                res.append("null")
            else:
                res.append(node.val)
                walk(node.left)
                walk(node.right)

        walk(root)

        return "[" + ",".join(str(val) for val in res) + "]"

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        items = [None if x == "null" else int(x) for x in data[1:-1].split(",")]

        def walk(items_it):
            try:
                val = next(items_it)
            except StopIteration:
                return None
            if val is None:
                return None
            else:
                res = TreeNode(val)
                res.left = walk(items_it)
                res.right = walk(items_it)
                return res

        return walk(iter(items))


#    n    >    l
#  l   c  >  a   n
# a b     >     b c
#
# a b c
# 1 1 1 ok
# 1 2 1 rotate_left(l) rotate_right(r)
# 2 1 1 rotate_right(n)
# 2 2 1 rotate_right(n)
# 1 1 2 ok
# 1 2 2 ok
# 2 1 2 ok
# 2 2 2 ok
class Solution:
    def rotate_left(self, node, node_depth):
        # print("before rotate_left", node)
        b = node.right.left
        node.right.left = node
        res = node.right
        node.right = b
        # print("after rotate_left", res)
        node_depth[res.left] = 1 + max(node_depth[res.left.left], node_depth[res.left.right])
        node_depth[res] = 1 + max(node_depth[res.left], node_depth[res.right])
        return res

    def rotate_right(self, node, node_depth):
        # print("before rotate_right", node)
        b = node.left.right
        node.left.right = node
        res = node.left
        node.left = b
        # print("after rotate_right", res)
        node_depth[res.right] = 1 + max(node_depth[res.right.left], node_depth[res.right.right])
        node_depth[res] = 1 + max(node_depth[res.left], node_depth[res.right])
        return res

    def balanceNode(self, node: TreeNode, node_depth: dict) -> (TreeNode, bool):  # returns node, depth
        # print("before balanceNode", node)
        if node is None:
            # print("after balanceNode", node)
            return node, False
        changed = False
        node.left, lchanged = self.balanceNode(node.left, node_depth)
        node.right, rchanged = self.balanceNode(node.right, node_depth)
        node_depth[node] = 1 + max(node_depth[node.left], node_depth[node.right])

        if node_depth[node.left] - node_depth[node.right] >= 2:
            if node_depth[node.left.right] > node_depth[node.left.left]:
                node.left = self.rotate_left(node.left, node_depth)
            node = self.rotate_right(node, node_depth)
            changed = True

        if node_depth[node.right] - node_depth[node.left] >= 2:
            if node_depth[node.right.left] > node_depth[node.right.right]:
                node.right = self.rotate_right(node.right, node_depth)
            node = self.rotate_left(node, node_depth)
            changed = True

        # print("after balanceNode", node)
        return node, lchanged or rchanged or changed

    def balanceBST(self, root: TreeNode) -> TreeNode:
        node_depth = {None: 0}
        changed = True
        while changed:
            root, changed = self.balanceNode(root, node_depth)
        return root


class Test(unittest.TestCase):
    def test(self):
        # root = TreeNode(1, None, TreeNode(2, None, TreeNode(3, None, TreeNode(4))))
        # [1, null,15, 14,17, 7,null,null,null, 2,12, null,3,9,null, null,null,null,11]
        # root = TreeNode(
        #     1,
        #     None,
        #     TreeNode(
        #         15,
        #         TreeNode(
        #             14,
        #             TreeNode(
        #                 7,
        #                 TreeNode(
        #                     2,
        #                     None,
        #                     TreeNode(3)
        #                 ),
        #                 TreeNode(
        #                     12,
        #                     TreeNode(
        #                         9,
        #                         None,
        #                         TreeNode(11)
        #                     ),
        #                     None
        #                 )
        #             )
        #         ),
        #         TreeNode(
        #             17,
        #         )
        #     )
        # )
        # print(root)
        root = TreeNode(
            15,
            TreeNode(
                14,
                TreeNode(
                    7,
                    TreeNode(
                        2,
                        None,
                        TreeNode(3)
                    ),
                    TreeNode(
                        12,
                        TreeNode(
                            9,
                            None,
                            TreeNode(11)
                        ),
                        None
                    )
                )
            ),
            TreeNode(
                17,
            )
        )
        root = Solution().balanceBST(root)
        print(root)
        # self.assertEqual(1, 1)
