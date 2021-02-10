import unittest
from typing import List
from itertools import chain


# from any 1 symbol we could get strong password in 5 steps
# from any 2 symbols we could get strong password in 4 steps
# from any 3 symbols we could get strong password in 3 steps
# from any 4 symbols we need from 2 to 3 steps to get strong password
# from any 5 symbols we need from 1 to 3 steps to get strong password
# from any 6 symbols we need from 0 to 3 steps to get strong password
# from any 7-20 symbols we need from 0 to 6 steps to get strong password
# from 21-50 symbols we need from n-20 to n-20+6 steps to get strong password
class Solution:
    def chars_types(self, password):
        upper, lower, digit = 0, 0, 0
        for char in password:
            if '0' <= char <= '9':
                digit += 1
            elif 'a' <= char <= 'z':
                lower += 1
            elif 'A' <= char < 'Z':
                upper += 1
        return (1 if lower > 0 else 0) + (1 if upper > 0 else 0) + (1 if digit > 0 else 0)

    def strongPasswordChecker(self, password: str) -> int:
        char_types = self.chars_types(password)
        if len(password) <= 5:
            return max(6 - len(password), 3 - char_types)

        prev = password[0]
        prev_pos = 0
        group_sizes = []
        for i, c in chain(enumerate(password), [(len(password), "")]):
            if c != prev:
                group_sizes.append(i - prev_pos)
                prev_pos, prev = i, c
        big_group_sizes = [x for x in group_sizes if x >= 3]
        total_len = len(password)
        res = 0
        while (len(big_group_sizes) > 0) and (total_len > 20):
            big_group_sizes.sort(key=lambda x: x%3, reverse=True)
            big_group_sizes[-1] -= 1
            if big_group_sizes[-1] < 3:
                big_group_sizes.pop()
            total_len -= 1
            res += 1

        for group_size in big_group_sizes:
            triplets = group_size // 3
            res += triplets
            char_types = min(3, char_types + triplets)
        res += 3 - char_types
        res += max(0, total_len - 20)
        return res


class Test(unittest.TestCase):
    def test(self):
        password = "a"
        out = 5
        self.assertEqual(Solution().strongPasswordChecker(password), out)
        password = "aa"
        out = 4
        self.assertEqual(Solution().strongPasswordChecker(password), out)
        password = "aaa"
        out = 3
        self.assertEqual(Solution().strongPasswordChecker(password), out)
        password = "aaaa"
        out = 2
        self.assertEqual(Solution().strongPasswordChecker(password), out)
        password = "aaaaa"
        out = 2
        self.assertEqual(Solution().strongPasswordChecker(password), out)
        password = "aaaaaa"
        out = 2
        self.assertEqual(Solution().strongPasswordChecker(password), out)
        password = "......"
        out = 3
        self.assertEqual(Solution().strongPasswordChecker(password), out)
        password = "aaaAAA"
        out = 2
        self.assertEqual(Solution().strongPasswordChecker(password), out)
        password = "aA1"
        out = 3
        self.assertEqual(Solution().strongPasswordChecker(password), out)
        password = "1337C0d3"
        out = 0
        self.assertEqual(Solution().strongPasswordChecker(password), out)
        password = "A1234567890aaabbbbccccc"
        out = 4
        self.assertEqual(Solution().strongPasswordChecker(password), out)
        password = "aaaaaaaAAAAAA6666bbbbaaaaaaABBC"
        out = 13
        self.assertEqual(Solution().strongPasswordChecker(password), out)
