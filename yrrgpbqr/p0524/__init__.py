import unittest
from typing import List


class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        next_char_pos = [[-1]*26 for _ in s + " "]
        for target_char in set(s):
            for i, char in reversed(list(enumerate(s))):
                if char == target_char:
                    next_char_pos[i][ord(target_char) - ord('a')] = i
                else:
                    next_char_pos[i][ord(target_char) - ord('a')] = next_char_pos[i + 1][ord(target_char) - ord('a')]
        for word in sorted(d, key = lambda x: (-len(x), x)):
            found = True
            pos = 0
            for char in word:
                code = ord(char) - ord('a')
                pos = next_char_pos[pos][code]
                if pos == -1:
                    found = False
                    break
                else:
                    pos += 1
            if found:
                return word
        return ""


class Test(unittest.TestCase):
    def test(self):
        s = "abpcplea"
        d = ["ale", "apple", "monkey", "plea"]
        out = "apple"
        self.assertEqual(Solution().findLongestWord(s, d), out)
        s = "aewfafwafjlwajflwajflwafj"
        d = ["apple", "ewaf", "awefawfwaf", "awef", "awefe", "ewafeffewafewf"]
        out = "ewaf"
        self.assertEqual(Solution().findLongestWord(s, d), out)
