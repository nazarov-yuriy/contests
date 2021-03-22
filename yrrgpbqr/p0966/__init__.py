import unittest
from typing import List


def replace_chars(s, chars, replacement):
    for char in chars:
        s = s.replace(char, replacement)
    return s


class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        orig = {}
        lower = {}
        no_vowel = {}
        for word in wordlist:
            orig[word] = [word]
            lower.setdefault(word.lower(), []).append(word)
            no_vowel.setdefault(replace_chars(word.lower(), ['a', 'e', 'i', 'o', 'u'], '_'), []).append(word)
        res = []
        for query in queries:
            if query in orig:
                res.append(query)
            elif query.lower() in lower:
                res.append(lower[query.lower()][0])
            elif replace_chars(query.lower(), ['a', 'e', 'i', 'o', 'u'], '_') in no_vowel:
                res.append(no_vowel[replace_chars(query.lower(), ['a', 'e', 'i', 'o', 'u'], '_')][0])
            else:
                res.append('')
        return res


class Test(unittest.TestCase):
    def test(self):
        wordlist = ["KiTe", "kite", "hare", "Hare"]
        queries = ["kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"]
        out = ["kite", "KiTe", "KiTe", "Hare", "hare", "", "", "KiTe", "", "KiTe"]
        self.assertEqual(Solution().spellchecker(wordlist, queries), out)
