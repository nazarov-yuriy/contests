import unittest
from typing import List
import heapq


class FreqStack:
    def __init__(self):
        self.heap = []  # (count, time, val)
        self.map = {}  # val: pos in heap
        self.stacks = {}  # val: [time]
        self.time = 0

    def push(self, x: int) -> None:
        self.stacks.setdefault(x, []).append(self.time)
        if x not in self.map:
            self.map[x] = len(self.heap)
            self.heap.append([0, -self.time, x])
        pos = self.map[x]
        self.heap[pos][0] -= 1
        self.heap[pos][1] = -self.time
        up_pos = (pos + 1) // 2 - 1
        while up_pos >= 0:
            if self.heap[pos] < self.heap[up_pos]:
                self.heap[pos], self.heap[up_pos] = self.heap[up_pos], self.heap[pos]
                self.map[self.heap[pos][2]] = pos
                self.map[self.heap[up_pos][2]] = up_pos
                pos = up_pos
                up_pos = (pos + 1) // 2 - 1
            else:
                break
        self.time += 1
        # print("after push", self.map, self.heap, self.stacks)

    def pop(self) -> int:
        # print("before pop", self.map, self.heap, self.stacks)
        res = self.heap[0]
        self.stacks[res[2]].pop()
        if res[0] == -1:
            del self.map[res[2]]
            last = self.heap.pop()
            if len(self.heap) == 0:
                return res[2]
            self.heap[0] = last
            self.map[last[2]] = 0
        else:
            self.heap[0][0] += 1
            self.heap[0][1] = -self.stacks[res[2]][-1]
        pos = 0
        while True:
            l, r = (pos + 1) * 2 - 1, (pos + 1) * 2 + 1 - 1
            if l >= len(self.heap):
                break
            else:
                if r >= len(self.heap):
                    next_val, next_pos = self.heap[l], l
                else:
                    next_val, next_pos = min((self.heap[l], l), (self.heap[r], r))
                if next_val < self.heap[pos]:
                    self.heap[pos], self.heap[next_pos] = self.heap[next_pos], self.heap[pos]
                    self.map[self.heap[pos][2]] = pos
                    self.map[self.heap[next_pos][2]] = next_pos
                    pos = next_pos
                else:
                    break
        return res[2]


class Test(unittest.TestCase):
    def test(self):
        # obj = FreqStack()
        # obj.push(5)
        # obj.push(7)
        # obj.push(5)
        # obj.push(7)
        # obj.push(4)
        # obj.push(5)
        # print(obj.pop())
        # print(obj.pop())
        # print(obj.pop())
        # print(obj.pop())
        # print(obj.pop())
        # print(obj.pop())
        # obj = FreqStack()
        # obj.push(4)
        # obj.push(0)
        # obj.push(9)
        # obj.push(3)
        # obj.push(4)
        # obj.push(2)
        # print(obj.pop())
        # obj.push(6)
        # print(obj.pop())
        # obj.push(1)
        # print(obj.pop())
        # obj.push(1)
        # print(obj.pop())
        # obj.push(4)
        # print(obj.pop())
        # print(obj.pop())
        # print(obj.pop())
        # print(obj.pop())
        # print(obj.pop())
        # print(obj.pop())
        obj = FreqStack()
        obj.push(5)
        obj.push(1)
        obj.push(2)
        obj.push(5)
        obj.push(5)
        obj.push(5)
        obj.push(1)
        obj.push(6)
        obj.push(1)
        obj.push(5)
        print(obj.pop())
        print(obj.pop())
        print(obj.pop())
        print(obj.pop())
        print(obj.pop())
        print(obj.pop())
        print(obj.pop())
        print(obj.pop())
        print(obj.pop())
        print(obj.pop())
        # obj = FreqStack()
        # nums = list([x % 17, x] for x in range(100, 0, -1))
        # heapq.heapify(nums)
        # obj.heap = list(nums)
        # obj.map = {count_val[1]: pos for pos, count_val in enumerate(nums)}
        # # print(nums)
        # while len(nums):
        #     heapq.heappop(nums)
        #     obj.pop()
        #     copy = list(obj.heap)
        #     heapq.heapify(copy)
        #     self.assertEqual(copy, obj.heap)
        # self.assertEqual(1, 1)
