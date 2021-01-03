import unittest


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


class Test(unittest.TestCase):
    def test(self):
        s = "lee(t(c)o)de)"
        self.assertEqual(Solution().minRemoveToMakeValid(s), "lee(t(c)o)de")
        s = "a)b(c)d"
        self.assertEqual(Solution().minRemoveToMakeValid(s), "ab(c)d")
        s = "))(("
        self.assertEqual(Solution().minRemoveToMakeValid(s), "")
        s = "(a(b(c)d)"
        self.assertEqual(Solution().minRemoveToMakeValid(s), "a(b(c)d)")
