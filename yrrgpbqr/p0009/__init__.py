import unittest

class Solution:
    def isPalindrome(self, x: int) -> bool:
        x_str = str(x)
        return list(x_str) == list(reversed(x_str))

class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().isPalindrome(121), True)
        self.assertEqual(Solution().isPalindrome(-121), False)
