import unittest
from typing import List


class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        chars = list(s)
        lr = []
        count = 0
        for char in chars:
            if char == '(':
                count += 1
            elif char == ')':
                if count == 0:
                    continue
                else:
                    count -= 1
            lr.append(char)
        res = []
        count = 0
        for char in reversed(lr):
            if char == ')':
                count += 1
            elif char == '(':
                if count == 0:
                    continue
                else:
                    count -= 1
            res.append(char)
        return "".join(reversed(res))

    def removeInvalidParentheses(self, s: str) -> List[str]:
        if len(s) == 0:
            return [""]

        char_balance = {"(": 1, ")": -1,}
        optimal_len = len(self.minRemoveToMakeValid(s))
        s_len = len(s)
        stack = []  # is removed
        res = set()

        def dfs(pos, balance, removed):
            if balance < 0:
                return
            if s_len - removed < optimal_len:
                return
            if pos == s_len:
                if balance == 0:
                    res.add("".join(c for i, c in enumerate(s) if stack[i] == 0))
                return
            if s[pos] == "(" or s[pos] == ")":
                stack.append(1)
                dfs(pos + 1, balance, removed + 1)
                stack.pop()
            stack.append(0)
            dfs(pos + 1, balance + char_balance.get(s[pos], 0), removed)
            stack.pop()

        dfs(0, 0, 0)
        return list(res)



class Test(unittest.TestCase):
    def test(self):
        s = "()())()"
        out = ["()()()", "(())()"]
        self.assertEqual(sorted(Solution().removeInvalidParentheses(s)), sorted(out))
        s = "(a)())()"
        out = ["(a)()()", "(a())()"]
        self.assertEqual(sorted(Solution().removeInvalidParentheses(s)), sorted(out))
        s = ")("
        out = [""]
        self.assertEqual(sorted(Solution().removeInvalidParentheses(s)), sorted(out))
        s = ""
        out = [""]
        self.assertEqual(sorted(Solution().removeInvalidParentheses(s)), sorted(out))
