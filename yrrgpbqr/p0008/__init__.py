import unittest


class Solution:
    def myAtoi(self, s: str) -> int:
        pos = 0
        while pos < len(s) and s[pos] == " ":
            pos += 1
        sign = 1
        if pos < len(s) and s[pos] in {"+", "-"}:
            if s[pos] == "-":
                sign = -1
            pos += 1
        num = 0
        while pos < len(s) and "0" <= s[pos] <= "9":
            num *= 10
            num += int(s[pos])
            pos += 1
        return max(min(sign * num, 2**31-1), -2**31)


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            42,
            Solution().myAtoi("42")
        )
        self.assertEqual(
            -42,
            Solution().myAtoi("  -42")
        )
        self.assertEqual(
            4193,
            Solution().myAtoi("4193 with words")
        )
        self.assertEqual(
            0,
            Solution().myAtoi("words and 987")
        )
        self.assertEqual(
            -2147483648,
            Solution().myAtoi("-91283472332")
        )
