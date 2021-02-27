import unittest
from typing import List


class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        pushed_pos = 0
        stack = []
        for num in popped:
            while pushed_pos < len(pushed) and (len(stack) == 0 or stack[-1] != num):
                stack.append(pushed[pushed_pos])
                pushed_pos += 1
            if pushed_pos == len(pushed) and (len(stack) == 0 or stack[-1] != num):
                return False
            stack.pop()
        return True


class Test(unittest.TestCase):
    def test(self):
        pushed = [1, 2, 3, 4, 5]
        popped = [4, 5, 3, 2, 1]
        out = True
        self.assertEqual(Solution().validateStackSequences(pushed, popped), out)
        pushed = [1, 2, 3, 4, 5]
        popped = [4, 3, 5, 1, 2]
        out = False
        self.assertEqual(Solution().validateStackSequences(pushed, popped), out)
        pushed = [8, 2, 1, 4, 7, 9, 0, 3, 5, 6]
        popped = [1, 2, 7, 3, 6, 4, 0, 9, 5, 8]
        # pu8 pu2 pu1 po1 pu4 pu7 po7
        out = False
        self.assertEqual(Solution().validateStackSequences(pushed, popped), out)
