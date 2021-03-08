import unittest
from typing import List
from collections import deque


class Robot:
    def __init__(self, map, x, y):
        self.x = 0
        self.y = 0
        self.direction = 0
        self.directions = [(0, -1), (1, 0), (0, 1), (-1, 0)]
        self.map = map
        self.dirty = [list(row) for row in map]

    def move(self):
        """
        Returns true if the cell in front is open and robot moves into the cell.
        Returns false if the cell in front is blocked and robot stays in the current cell.
        :rtype bool
        """
        x, y = self.x, self.y
        dx, dy = self.directions[self.direction]
        if 0 <= x + dx < len(self.map[0]) and 0 <= y + dy < len(self.map) and self.map[y + dy][x + dx] == 1:
            self.x += dx
            self.y += dy
            return True
        return False

    def turnLeft(self):
        """
        Robot will stay in the same cell after calling turnLeft/turnRight.
        Each turn will be 90 degrees.
        :rtype void
        """
        self.direction = (self.direction + 3) % len(self.directions)

    def turnRight(self):
        """
        Robot will stay in the same cell after calling turnLeft/turnRight.
        Each turn will be 90 degrees.
        :rtype void
        """
        self.direction = (self.direction + 1) % len(self.directions)

    def clean(self):
        """
        Clean the current cell.
        :rtype void
        """
        self.dirty[self.y][self.x] = 0


class Solution:
    EMPTY = 1
    OBSTACLE = 0

    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        map = {(0, 0): self.EMPTY}
        robot_direction = 0
        directions = [(0, -1), (1, 0), (0, 1), (-1, 0)]

        def dfs(x, y):
            robot.clean()
            nonlocal robot_direction
            for direction, (dx, dy) in enumerate(directions):
                if (x + dx, y + dy) in map:
                    continue
                while robot_direction != direction:
                    robot.turnRight()
                    robot_direction = (robot_direction + 1) % len(directions)
                if robot.move():
                    map[(x + dx, y + dy)] = self.EMPTY
                    dfs(x + dx, y + dy)
                    while robot_direction != (direction + 2) % len(directions):
                        robot.turnRight()
                        robot_direction = (robot_direction + 1) % len(directions)
                    robot.move()
                else:
                    map[(x + dx, y + dy)] = self.OBSTACLE

        dfs(0, 0)


class Test(unittest.TestCase):
    def test(self):
        room = [
            [1, 1, 1, 1, 1, 0, 1, 1],
            [1, 1, 1, 1, 1, 0, 1, 1],
            [1, 0, 1, 1, 1, 1, 1, 1],
            [0, 0, 0, 1, 0, 0, 0, 0],
            [1, 1, 1, 1, 1, 1, 1, 1]
        ]
        row = 1
        col = 3
        robot = Robot(room, col, row)
        Solution().cleanRoom(robot)
        self.assertEqual(sum(sum(row) for row in robot.dirty), 0)
