import unittest
from typing import List
from itertools import chain
from collections import deque


class Node:
    def __init__(self, word, distance, prev):
        self.word = word
        self.distance = distance
        self.prev = prev


class Solution:
    def listToArray(self, node):
        res = []
        while node is not None:
            res.append(node.word)
            node = node.prev
        return res

    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
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
        queue.append(Node(beginWord, 1, None))
        seen = set()
        res = []
        while len(queue) > 0:
            node = queue.popleft()
            if len(res) > 0:
                if node.distance > len(res[0]):
                    continue
            if node.word == endWord:
                res.append(list(reversed(self.listToArray(node))))
                continue
            seen.add(node.word)
            for neighbor in connected.get(node.word, []):
                if neighbor not in seen:
                    queue.append(Node(neighbor, node.distance + 1, node))
        return res


class Test(unittest.TestCase):
    def test(self):
        beginWord = "hit"
        endWord = "cog"
        wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
        out = [
            ["hit", "hot", "dot", "dog", "cog"],
            ["hit", "hot", "lot", "log", "cog"]
        ]
        self.assertEqual(sorted(Solution().findLadders(beginWord, endWord, wordList)), sorted(out))
        beginWord = "hit"
        endWord = "cog"
        wordList = ["hot", "dot", "dog", "lot", "log"]
        out = []
        self.assertEqual(sorted(Solution().findLadders(beginWord, endWord, wordList)), sorted(out))
