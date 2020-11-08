import unittest

class Solution:
    def convertToTitle(self, n: int) -> str:
        if n <= 26:
            return chr(ord("A") + n - 1)
        else:
            n -= 1
            return self.convertToTitle(n // 26) + self.convertToTitle(n % 26 + 1)

class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().convertToTitle(1), "A")
        self.assertEqual(Solution().convertToTitle(28), "AB")
        self.assertEqual(Solution().convertToTitle(701), "ZY")
        self.assertEqual(Solution().convertToTitle(702), "ZZ")
        self.assertEqual(Solution().convertToTitle(703), "AAA")
