import unittest
from typing import List
from collections import Counter
from textwrap import indent


class TreeNode:
    def __init__(self, key, val, left=None, right=None, parent=None):
        self.key = key
        self.val = val
        self.left = left
        self.left_count = 0
        self.left_depth = 0
        self.right = right
        self.right_count = 0
        self.right_depth = 0
        self.parent = parent

    def __repr__(self):
        v = indent(f"{self.key}:{self.val}:l{self.left_depth}:r{self.right_depth}", "    ")
        l = indent(repr(self.left), "    ")
        r = indent(repr(self.right), "    ")
        return f"TreeNode(\n{v},\n{l},\n{r}\n)"

class AVLTree:
    def __init__(self):
        self.root = None

    def __repr__(self):
        return f"AVLTree({self.root})"

    def update_depth_counts_left(self, node):
        left = node.left
        if left is not None:
            node.left_count = left.val + left.left_count + left.right_count
            node.left_depth = 1 + max(left.left_depth, left.right_depth)
        else:
            node.left_depth = 0
            node.left_count = 0

    def update_depth_counts_right(self, node):
        right = node.right
        if right is not None:
            node.right_count = right.val + right.left_count + right.right_count
            node.right_depth = 1 + max(right.left_depth, right.right_depth)
        else:
            node.right_depth = 0
            node.right_count = 0

    def update_depth_counts(self, node):
        left = node.left
        if left is not None:
            node.left_count = left.val + left.left_count + left.right_count
            node.left_depth = 1 + max(left.left_depth, left.right_depth)
        right = node.right
        if right is not None:
            node.right_count = right.val + right.left_count + right.right_count
            node.right_depth = 1 + max(right.left_depth, right.right_depth)

    def update_counts(self, node):
        left = node.left
        if left is not None:
            node.left_count = left.val + left.left_count + left.right_count
        right = node.right
        if right is not None:
            node.right_count = right.val + right.left_count + right.right_count

    #    x      >      z
    #   / \     >     / \
    # t1   z    >    x   t4
    #     / \   >   / \
    #   t23  t4 > t1  t23
    def rotate_left(self, x, z):
        # print("rotate_left", x, z)
        t23 = z.left
        x.right = t23
        if t23 is not None:
            t23.parent = x
        if x.parent is not None:
            if x.parent.left == x:
                x.parent.left = z
            else:
                x.parent.right = z
        else:
            self.root = z
        z.parent = x.parent
        z.left = x
        x.parent = z
        self.update_depth_counts_right(x)
        self.update_depth_counts_left(z)

    def rotate_right(self, x, z):
        # print("rotate_right", x, z)
        t23 = z.right
        x.left = t23
        if t23 is not None:
            t23.parent = x
        if x.parent is not None:
            if x.parent.left == x:
                x.parent.left = z
            else:
                x.parent.right = z
        else:
            self.root = z
        z.parent = x.parent
        z.right = x
        x.parent = z
        self.update_depth_counts_left(x)
        self.update_depth_counts_right(z)

    def rotate_right_left(self, x, z):
        # print("rotate_right_left", x, z)
        y = z.left
        t3 = y.right
        z.left = t3
        if t3 is not None:
            t3.parent = z
        y.right = z
        z.parent = y
        t2 = y.left
        x.right = t2
        if t2 is not None:
            t2.parent = x
        if x.parent is not None:
            if x.parent.left == x:
                x.parent.left = y
            else:
                x.parent.right = y
        else:
            self.root = y
        y.parent = x.parent
        y.left = x
        x.parent = y
        self.update_depth_counts_right(x)
        self.update_depth_counts_left(z)
        self.update_depth_counts(y)
        # for node in [x, z, y]:
        #     self.update_depth_counts_rotation(node)

    def rotate_left_right(self, x, z):
        # print("rotate_left_right", x, z)
        y = z.right
        t3 = y.left
        z.right = t3
        if t3 is not None:
            t3.parent = z
        y.left = z
        z.parent = y
        t2 = y.right
        x.left = t2
        if t2 is not None:
            t2.parent = x
        if x.parent is not None:
            if x.parent.left == x:
                x.parent.left = y
            else:
                x.parent.right = y
        else:
            self.root = y
        y.parent = x.parent
        y.right = x
        x.parent = y
        # for node in [x, z, y]:
        #     self.update_depth_counts_rotation(node)
        self.update_depth_counts_left(x)
        self.update_depth_counts_right(z)
        self.update_depth_counts(y)

    def upsert(self, key, val=1):
        if self.root is None:
            self.root = TreeNode(key, val)
        else:
            node = self.root
            while True:
                if key < node.key:
                    if node.left is None:
                        node.left = TreeNode(key, val, parent=node)
                        break
                    else:
                        node = node.left
                elif node.key < key:
                    if node.right is None:
                        node.right = TreeNode(key, val, parent=node)
                        break
                    else:
                        node = node.right
                else:
                    node.val = val
                    node = node.parent  # skip handling current node
                    while node is not None:
                        self.update_counts(node)
                        node = node.parent
                    return
            while node is not None:
                self.update_depth_counts(node)
                parent = node.parent
                if node.right_depth > node.left_depth + 1:
                    if node.right.right_depth >= node.right.left_depth:
                        self.rotate_left(node, node.right)
                    else:
                        self.rotate_right_left(node, node.right)
                elif node.left_depth > node.right_depth + 1:
                    if node.left.left_depth >= node.left.right_depth:
                        self.rotate_right(node, node.left)
                    else:
                        self.rotate_left_right(node, node.left)
                node = parent

    def get_left_right_count(self, key):
        left_count, right_count = 0, 0
        node = self.root
        while True:
            if key < node.key:
                right_count += node.right_count + node.val
                node = node.left
            elif node.key < key:
                left_count += node.left_count + node.val
                node = node.right
            else:
                break
        return left_count + node.left_count, right_count + node.right_count

class Solution:
    def createSortedArrayAVL(self, instructions: List[int]) -> int:
        tree = AVLTree()
        c = Counter()
        res = 0
        for num in instructions:
            c[num] += 1
            tree.upsert(num, c[num])
            l, r = tree.get_left_right_count(num)
            res += min(l, r)
        return res % (10**9 + 7)

    def createSortedArray(self, instructions: List[int]) -> int:
        if len(instructions) == 0:
            return 0
        max_inst = max(instructions)
        fenwick_size = max_inst + 1
        fenwick = [0] * fenwick_size
        def inc_fenwick(fenwick, pos, size):
            bit = 1
            while pos < size:
                if pos & bit:
                    fenwick[pos] += 1
                    pos += bit
                bit <<= 1
        def get_fenwick(fenwick, pos, size):
            res = 0
            bit = 1
            while pos:
                if pos & bit:
                    res += fenwick[pos]
                    pos -= bit
                bit <<= 1
            return res
        res = 0
        for i, num in enumerate(instructions):
            inc_fenwick(fenwick, num, fenwick_size)
            l = get_fenwick(fenwick, num - 1, fenwick_size)
            r = i + 1 - get_fenwick(fenwick, num, fenwick_size)
            res += min(l, r)
        return res % (10**9+7)


class Test(unittest.TestCase):
    def test(self):
        instructions = []
        out = 0
        self.assertEqual(Solution().createSortedArray(instructions), out)
        instructions = [1, 5, 6, 2]
        out = 1
        self.assertEqual(Solution().createSortedArray(instructions), out)
        instructions = [1, 2, 3, 6, 5, 4]
        out = 3
        self.assertEqual(Solution().createSortedArray(instructions), out)
        instructions = [1, 3, 3, 3, 2, 4, 2, 1, 2]
        out = 4
        self.assertEqual(Solution().createSortedArray(instructions), out)
