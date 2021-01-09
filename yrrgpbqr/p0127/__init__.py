import unittest
from typing import List
from itertools import chain
from collections import deque


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        groups = {}  # {("prefix", "suffix"):[]}
        if beginWord in wordList:
            wordist_it = iter(wordList)
        else:
            wordist_it = iter(chain(wordList, [beginWord]))
        for word in wordist_it:
            for skip_pos in range(len(word)):
                groups.setdefault((word[:skip_pos], word[skip_pos + 1:]), []).append(word)

        connected = {}  # {word: {"word", "word", ...}, ...}
        for group in groups.values():
            for word in group:
                for transformed in group:
                    if word != transformed:
                        connected.setdefault(word, set()).add(transformed)

        # bfs
        queue = deque()
        queue.append((beginWord, 1))
        seen = {beginWord}
        while len(queue) > 0:
            word, distance = queue.popleft()
            if word == endWord:
                return distance
            for neighbor in connected.get(word, []):
                if neighbor not in seen:
                    queue.append((neighbor, distance + 1))
                    seen.add(neighbor)
        return 0


class Test(unittest.TestCase):
    def test(self):
        beginWord = "hit"
        endWord = "cog"
        wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
        self.assertEqual(Solution().ladderLength(beginWord, endWord, wordList), 5)
        beginWord = "hit"
        endWord = "cog"
        wordList = ["hot", "dot", "dog", "lot", "log"]
        self.assertEqual(Solution().ladderLength(beginWord, endWord, wordList), 0)
