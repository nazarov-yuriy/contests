import unittest
from typing import List


class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        piece_by_head = {
            piece[0]: piece for piece in pieces
        }
        pos = 0
        while pos < len(arr):
            piece = piece_by_head.get(arr[pos])
            if piece is None:
                return False
            if piece != arr[pos:pos+len(piece)]:
                return False
            pos += len(piece)
        return True


class Test(unittest.TestCase):
    def test(self):
        arr = [85]
        pieces = [[85]]
        self.assertEqual(Solution().canFormArray(arr, pieces), True)
        arr = [15, 88]
        pieces = [[88], [15]]
        self.assertEqual(Solution().canFormArray(arr, pieces), True)
        arr = [49, 18, 16]
        pieces = [[16, 18, 49]]
        self.assertEqual(Solution().canFormArray(arr, pieces), False)
        arr = [91, 4, 64, 78]
        pieces = [[78], [4, 64], [91]]
        self.assertEqual(Solution().canFormArray(arr, pieces), True)
        arr = [1, 3, 5, 7]
        pieces = [[2, 4, 6, 8]]
        self.assertEqual(Solution().canFormArray(arr, pieces), False)
