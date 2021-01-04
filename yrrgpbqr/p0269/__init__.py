import unittest
from typing import List
from collections import deque


class Solution:
    def alienOrder(self, words: List[str]) -> str:
        max_len = max(len(word) for word in words)
        char2prev = {"": set()}
        prev2char = {}
        chunks = {"": words}
        for pos in range(max_len):
            next_chunks = {}
            for key, chunk in chunks.items():
                seen = {""}
                for word in chunk:
                    if len(word) > pos:
                        char = word[pos]
                        next_chunks.setdefault(key + char, []).append(word)
                    else:
                        char = ""
                    for prev in seen:
                        if prev != char:
                            char2prev.setdefault(char, set()).add(prev)
                            prev2char.setdefault(prev, set()).add(char)
                    seen.add(char)
                chunks = next_chunks
        # res = ""
        # while len(char2prev) > 0:
        #     stuck = True
        #     for char, prevs in list(char2prev.items()):
        #         if len(prevs) == 0:
        #             res += char
        #             del char2prev[char]
        #             for left_prevs in char2prev.values():
        #                 left_prevs.discard(char)
        #             stuck = False
        #     if stuck:
        #         return ""
        # return res
        res = []
        q = deque(char for char, prevs in char2prev.items() if len(prevs) == 0)
        while len(q) > 0:
            prev = q.popleft()
            res.append(prev)
            for char in prev2char.get(prev, []):
                if prev in char2prev[char]:
                    char2prev[char].remove(prev)
                    if len(char2prev[char]) == 0:
                        q.append(char)
            del char2prev[prev]
        if len(char2prev) > 0:
            return ""
        return "".join(res)


class Test(unittest.TestCase):
    def test(self):
        words = ["wrt", "wrf", "er", "ett", "rftt"]
        self.assertEqual(Solution().alienOrder(words), "wertf")
        words = words = ["z", "x"]
        self.assertEqual(Solution().alienOrder(words), "zx")
        words = words = ["z","x","z"]
        self.assertEqual(Solution().alienOrder(words), "")
