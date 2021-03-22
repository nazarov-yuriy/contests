import unittest
from typing import List


class UndergroundSystem:

    def __init__(self):
        self.checkins = {}
        self.times = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkins[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        checkin = self.checkins[id]
        del self.checkins[id]
        time = self.times.setdefault((checkin[0], stationName), [0, 0])
        time[0] += t - checkin[1]
        time[1] += 1

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        sum_time, cnt = self.times[(startStation, endStation)]
        return sum_time / cnt


class Test(unittest.TestCase):
    def test(self):
        undergroundSystem = UndergroundSystem()
        undergroundSystem.checkIn(45, "Leyton", 3);
        undergroundSystem.checkIn(32, "Paradise", 8);
        undergroundSystem.checkIn(27, "Leyton", 10);
        undergroundSystem.checkOut(45, "Waterloo", 15);
        undergroundSystem.checkOut(27, "Waterloo", 20);
        undergroundSystem.checkOut(32, "Cambridge", 22);
        self.assertEqual(undergroundSystem.getAverageTime("Paradise", "Cambridge"), 14.)
        self.assertEqual(undergroundSystem.getAverageTime("Leyton", "Waterloo"), 11.)
        undergroundSystem.checkIn(10, "Leyton", 24);
        self.assertEqual(undergroundSystem.getAverageTime("Leyton", "Waterloo"), 11.)
        undergroundSystem.checkOut(10, "Waterloo", 38);
        self.assertEqual(undergroundSystem.getAverageTime("Leyton", "Waterloo"), 12.)
