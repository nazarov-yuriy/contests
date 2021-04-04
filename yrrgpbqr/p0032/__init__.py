import unittest
from typing import List


class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = []
        res = 0
        consecutive = 0
        for i, char in enumerate(s):
            if char == '(':
                stack.append([i, 0])
            else:
                if len(stack) > 0:
                    open_pos, inner_consecutive = stack.pop()
                    l = i - open_pos + 1
                    if len(stack) > 0:
                        stack[-1][1] += l
                        res = max(res, stack[-1][1])
                    else:
                        consecutive += l
                        res = max(res, consecutive)
                else:
                    consecutive = 0
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "(()"
        out = 2
        self.assertEqual(Solution().longestValidParentheses(s), out)
        s = ")()())"
        out = 4
        self.assertEqual(Solution().longestValidParentheses(s), out)
        s = ""
        out = 0
        self.assertEqual(Solution().longestValidParentheses(s), out)
