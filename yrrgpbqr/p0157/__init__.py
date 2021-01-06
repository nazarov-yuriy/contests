import unittest
from typing import List


data = []

def read4(buf4: List[str]) -> int:
    buf4[0], buf4[1], buf4[2], buf4[3] = data.pop(0), data.pop(0), data.pop(0), data.pop(0)


class Solution:
    def __init__(self):
        self.buf = ["0", "0", "0", "0"]
        self.pos = 4

    def getChar(self):
        if self.pos >= len(self.buf):
            new_len = read4(self.buf)
            if new_len == 0:
                return ""
            self.buf = self.buf[:new_len]
            self.pos = 0
        res = self.buf[self.pos]
        self.pos += 1
        return res

    def read(self, buf: List[str], n: int) -> int:
        for i in range(n):
            char = self.getChar()
            if char == "":
                return i
            buf[i] = char
        return n


class Test(unittest.TestCase):
    def test(self):
        data.extend(["a","b","c","d","e","f","g","h"])
        s = Solution()
        buf = [None, None, None]
        s.read(buf, 3)
        self.assertEqual(buf, ["a", "b", "c"])
        s.read(buf, 3)
        self.assertEqual(buf, ["d", "e", "f"])
