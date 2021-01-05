import unittest
from typing import List
from collections import Counter
from itertools import chain
import heapq


class WordDictionary:
    INF = int(1e9)

    def __init__(self, max_len=500):
        self.next_id = 0
        self.words_with_len = [0] * (max_len + 1)
        self.words_with_char_at_pos = [[{} for _ in range(max_len + 1)] for _ in range(max_len + 1)]

    def addWord(self, word: str) -> None:
        word_len = len(word)
        self.words_with_len[word_len] += 1
        for i, c in enumerate(word):
            self.words_with_char_at_pos[word_len][i].setdefault(c, []).append(self.next_id)
        self.next_id += 1

    def firstIntersection(self, to_intersect):
        # if min(len(x) for x in to_intersect) == 0:
        #     return None
        positions = [0] * len(to_intersect)
        heap = [(ids[positions[i]], i) for i, ids in enumerate(to_intersect)]
        heapq.heapify(heap)
        current_id = None
        current_count = 1
        while True:
            doc_id, list_idx = heapq.heappop(heap)
            if doc_id == self.INF:
                break
            if current_id != doc_id:
                current_id = doc_id
                current_count = 1
            else:
                current_count += 1
            if current_count == len(to_intersect):
                return doc_id
            positions[list_idx] += 1
            if positions[list_idx] >= len(to_intersect[list_idx]):
                heapq.heappush(heap, (self.INF, list_idx))
            else:
                heapq.heappush(heap, (to_intersect[list_idx][positions[list_idx]], list_idx))
        return None

    def search(self, word: str) -> bool:
        word_len = len(word)
        to_intersect = []
        for i, c in enumerate(word):
            if c != ".":
                candidates = self.words_with_char_at_pos[word_len][i].get(c, [])
                if len(candidates) == 0:
                    return False
                to_intersect.append(candidates)
        if len(to_intersect) > 0:
            return self.firstIntersection(to_intersect) is not None
        else:
            return self.words_with_len[word_len] > 0


class Test(unittest.TestCase):
    def test(self):
        wordDictionary = WordDictionary()
        self.assertEqual(wordDictionary.search("..."), False)
        wordDictionary.addWord("bad")
        self.assertEqual(wordDictionary.search("..."), True)
        wordDictionary.addWord("dad")
        wordDictionary.addWord("mad")
        self.assertEqual(wordDictionary.search(".."), False)
        self.assertEqual(wordDictionary.search("...."), False)
        self.assertEqual(wordDictionary.search("pad"), False)
        self.assertEqual(wordDictionary.search("bad"), True)
        self.assertEqual(wordDictionary.search(".ad"), True)
        self.assertEqual(wordDictionary.search("b.."), True)
        for _ in range(5000):
            wordDictionary.addWord("x" * 500)
        for _ in range(5000):
            wordDictionary.search("x" * 500)
