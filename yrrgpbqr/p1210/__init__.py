import unittest
from typing import List


class Solution:
    HORIZONTAL = 0  # (y, x-1) (y, x)
    VERTICAL = 1  # (y-1, x) (y, x)

    def move_right(self, y, x, orientation):
        return y, x + 1, orientation

    def check_right(self, grid, y, x, orientation):
        if x + 1 >= len(grid[y]):
            return False
        if orientation == self.HORIZONTAL:
            return grid[y][x + 1] == 0
        else:
            return grid[y][x + 1] == 0 and grid[y - 1][x + 1] == 0

    def move_down(self, y, x, orientation):
        return y + 1, x, orientation

    def check_down(self, grid, y, x, orientation):
        if y + 1 >= len(grid):
            return False
        if orientation == self.HORIZONTAL:
            return grid[y + 1][x] == 0 and grid[y + 1][x - 1] == 0
        else:
            return grid[y + 1][x] == 0

    def rotate_cw(self, y, x, orientation):
        return y + 1, x - 1, self.VERTICAL

    def check_cw(self, grid, y, x, orientation):
        if orientation == self.VERTICAL:
            return False
        return self.check_down(grid, y, x, orientation)

    def rotate_ccw(self, y, x, orientation):
        return y - 1, x + 1, self.HORIZONTAL

    def check_ccw(self, grid, y, x, orientation):
        if orientation == self.HORIZONTAL:
            return False
        return self.check_right(grid, y, x, orientation)

    def minimumMoves(self, grid: List[List[int]]) -> int:
        N = 100
        INF = N * N * 4
        reachability = [
            [[INF, INF] for _ in row]
            for row in grid
        ]
        wave = 0

        reachability[0][1][self.HORIZONTAL] = wave
        queue = {(0, 1, self.HORIZONTAL)}
        new_queue = set()
        wave += 1

        while len(queue) > 0:
            for y, x, orientation in queue:
                for check, action in [
                    (self.check_right, self.move_right),
                    (self.check_down, self.move_down),
                    (self.check_cw, self.rotate_cw),
                    (self.check_ccw, self.rotate_ccw),
                ]:
                    if check(grid, y, x, orientation):
                        new_pos = action(y, x, orientation)
                        if reachability[new_pos[0]][new_pos[1]][new_pos[2]] == INF:
                            reachability[new_pos[0]][new_pos[1]][new_pos[2]] = wave
                            new_queue.add(new_pos)
            queue = new_queue
            new_queue = set()
            wave += 1
        if reachability[-1][-1][self.HORIZONTAL] == INF:
            return -1
        else:
            return reachability[-1][-1][self.HORIZONTAL]


class Test(unittest.TestCase):
    def test(self):
        grid = [
            [0, 0],
            [0, 0]
        ]
        self.assertEqual(Solution().minimumMoves(grid), 1)
        grid = [[0, 0, 0, 0, 0, 1],
                [1, 1, 0, 0, 1, 0],
                [0, 0, 0, 0, 1, 1],
                [0, 0, 1, 0, 1, 0],
                [0, 1, 1, 0, 0, 0],
                [0, 1, 1, 0, 0, 0]]
        self.assertEqual(Solution().minimumMoves(grid), 11)
        grid = [[0, 0, 1, 1, 1, 1],
                [0, 0, 0, 0, 1, 1],
                [1, 1, 0, 0, 0, 1],
                [1, 1, 1, 0, 0, 1],
                [1, 1, 1, 0, 0, 1],
                [1, 1, 1, 0, 0, 0]]
        self.assertEqual(Solution().minimumMoves(grid), 9)
        grid = [
            [0,0,0,0,0,0,0,0,0,1],
            [0,1,0,0,0,0,0,1,0,1],
            [1,0,0,1,0,0,1,0,1,0],
            [0,0,0,1,0,1,0,1,0,0],
            [0,0,0,0,1,0,0,0,0,1],
            [0,0,1,0,0,0,0,0,0,0],
            [1,0,0,1,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0],
            [1,1,0,0,0,0,0,0,0,0]
        ]
        self.assertEqual(Solution().minimumMoves(grid), -1)

