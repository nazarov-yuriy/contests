import unittest
from typing import List


class Solution:
    def maximumSwap(self, num: int) -> int:
        chars = list(str(num))
        max_char_pos = -1
        max_char = chars[max_char_pos]
        last_inversion = (-1, -1)
        for i, char in reversed(list(enumerate(chars))):
            if char > max_char:
                max_char = char
                max_char_pos = i
            elif char < max_char:
                last_inversion = (max_char_pos, i)
        chars[last_inversion[0]], chars[last_inversion[1]] = chars[last_inversion[1]], chars[last_inversion[0]]
        return int("".join(chars))


class Test(unittest.TestCase):
    def test(self):
        num = 2736
        out = 7236
        self.assertEqual(Solution().maximumSwap(num), out)
        num = 9973
        out = 9973
        self.assertEqual(Solution().maximumSwap(num), out)
        num = 0
        out = 0
        self.assertEqual(Solution().maximumSwap(num), out)
        num = 10
        out = 10
        self.assertEqual(Solution().maximumSwap(num), out)
        num = 3312
        out = 3321
        self.assertEqual(Solution().maximumSwap(num), out)

