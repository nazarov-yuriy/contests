import unittest


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    def __eq__(self, other):
        if other is None:
            return 0
        return self.val == other.val and self.left == other.left and self.right == other.right


class Codec:
    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        res = []

        def walk(node):
            if node is None:
                res.append(None)
            else:
                res.append(node.val)
                walk(node.left)
                walk(node.right)

        walk(root)

        return " ".join(str(val) for val in res)

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        items = [None if x == "None" else int(x) for x in data.split(" ")]

        def walk(items_it):
            val = next(items_it)
            if val is None:
                return None
            else:
                res = TreeNode(val)
                res.left = walk(items_it)
                res.right = walk(items_it)
                return res

        return walk(iter(items))


class Test(unittest.TestCase):
    def test(self):
        ser = Codec()
        deser = Codec()

        root = TreeNode(1)
        tree = ser.serialize(root)
        ans = deser.deserialize(tree)
        self.assertEqual(root, ans)

        root = TreeNode(2)
        root.left = TreeNode(1)
        root.right = TreeNode(3)
        tree = ser.serialize(root)
        ans = deser.deserialize(tree)
        self.assertEqual(root, ans)
