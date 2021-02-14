import unittest
from typing import List
from copy import deepcopy


class Solution:
    def check_r(self, board, r, c, n):
        return n not in board[r]

    def check_c(self, board, r, c, n):
        return n not in [row[c] for row in board]

    def check_s(self, board, r, c, n):
        s = board[(r // 3) * 3 + 0][(c // 3) * 3:(c // 3 + 1) * 3] + \
            board[(r // 3) * 3 + 1][(c // 3) * 3:(c // 3 + 1) * 3] + \
            board[(r // 3) * 3 + 2][(c // 3) * 3:(c // 3 + 1) * 3]
        return n not in s

    def fillExact(self, board):
        row_groups = [[(r, c) for c in range(9)] for r in range(9)]
        col_groups = [[(r, c) for r in range(9)] for c in range(9)]
        sqr_groups = [[(r + 0, c + 0), (r + 0, c + 1), (r + 0, c + 2),
                       (r + 1, c + 0), (r + 1, c + 1), (r + 1, c + 2),
                       (r + 2, c + 0), (r + 2, c + 1), (r + 2, c + 2), ] for r in range(0, 9, 3) for c in
                      range(0, 9, 3)]
        changed = False
        for num in "123456789":
            for groups in [
                row_groups,
                col_groups,
                sqr_groups,
            ]:
                for group in groups:
                    counts = 0
                    present = 0
                    coord = None
                    for (r, c) in group:
                        if board[r][c] == num:
                            present += 1
                        elif board[r][c] == "." and self.check_r(board, r, c, num) and self.check_c(board, r, c,
                                                                                                    num) and self.check_s(
                            board, r, c, num):
                            counts += 1
                            coord = (r, c)
                    if present == 0 and counts == 0:
                        raise RuntimeError("wrong")
                    if counts == 1:
                        board[coord[0]][coord[1]] = num
                        # print(coord, num)
                        # print(".")
                        changed = True
        return changed

    def solveSudoku(self, board: List[List[str]]) -> None:
        while self.fillExact(board):
            pass
        # print("#" * 40)
        # for row in board:
        #     print(row)
        er, ec = None, None
        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    er, ec = r, c
        if er is None:
            return
        else:
            for num in "123456789":
                cr = self.check_r(board, er, ec, num)
                cc = self.check_c(board, er, ec, num)
                cs = self.check_s(board, er, ec, num)
                # print(er, ec, num, cr, cc, cs)
                if cr and cc and cs:
                    copy_board = deepcopy(board)
                    board[er][ec] = num
                    try:
                        self.solveSudoku(board)
                        return
                    except RuntimeError:
                        # print("wrong")
                        for r in range(9):
                            for c in range(9):
                                board[r][c] = copy_board[r][c]
            raise RuntimeError("wrong")


class Test(unittest.TestCase):
    def test(self):
        board = [
            ["5", "3", ".", ".", "7", ".", ".", ".", "."],
            ["6", ".", ".", "1", "9", "5", ".", ".", "."],
            [".", "9", "8", ".", ".", ".", ".", "6", "."],
            ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
            ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
            ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
            [".", "6", ".", ".", ".", ".", "2", "8", "."],
            [".", ".", ".", "4", "1", "9", ".", ".", "5"],
            [".", ".", ".", ".", "8", ".", ".", "7", "9"],
        ]
        solved = [
            ['5', '3', '4', '6', '7', '8', '9', '1', '2'],
            ['6', '7', '2', '1', '9', '5', '3', '4', '8'],
            ['1', '9', '8', '3', '4', '2', '5', '6', '7'],
            ['8', '5', '9', '7', '6', '1', '4', '2', '3'],
            ['4', '2', '6', '8', '5', '3', '7', '9', '1'],
            ['7', '1', '3', '9', '2', '4', '8', '5', '6'],
            ['9', '6', '1', '5', '3', '7', '2', '8', '4'],
            ['2', '8', '7', '4', '1', '9', '6', '3', '5'],
            ['3', '4', '5', '2', '8', '6', '1', '7', '9'],
        ]
        Solution().solveSudoku(board)
        # for row in board:
        #     print(row)
        self.assertEqual(board, solved)
        board = [
            [".", ".", "9", "7", "4", "8", ".", ".", "."],
            ["7", ".", ".", ".", ".", ".", ".", ".", "."],
            [".", "2", ".", "1", ".", "9", ".", ".", "."],
            [".", ".", "7", ".", ".", ".", "2", "4", "."],
            [".", "6", "4", ".", "1", ".", "5", "9", "."],
            [".", "9", "8", ".", ".", ".", "3", ".", "."],
            [".", ".", ".", "8", ".", "3", ".", "2", "."],
            [".", ".", ".", ".", ".", ".", ".", ".", "6"],
            [".", ".", ".", "2", "7", "5", "9", ".", "."]
        ]
        Solution().solveSudoku(board)
        solved = [
            ['5', '1', '9', '7', '4', '8', '6', '3', '2'],
            ['7', '8', '3', '6', '5', '2', '4', '1', '9'],
            ['4', '2', '6', '1', '3', '9', '8', '7', '5'],
            ['3', '5', '7', '9', '8', '6', '2', '4', '1'],
            ['2', '6', '4', '3', '1', '7', '5', '9', '8'],
            ['1', '9', '8', '5', '2', '4', '3', '6', '7'],
            ['9', '7', '5', '8', '6', '3', '1', '2', '4'],
            ['8', '3', '2', '4', '9', '1', '7', '5', '6'],
            ['6', '4', '1', '2', '7', '5', '9', '8', '3'],
        ]
        Solution().solveSudoku(board)
        # for row in board:
        #     print(row)
        self.assertEqual(board, solved)
