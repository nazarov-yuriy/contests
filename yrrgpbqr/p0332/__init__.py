import unittest
from typing import List


class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        dst_by_src = {}
        for src, dst in tickets:
            dst_by_src.setdefault(src, []).append(dst)
        itinerary = []

        def do_flight(src, dst):
            dst_by_src[src].remove(dst)
            itinerary.append(dst)
            if len(itinerary) == len(tickets):
                return
            for next in sorted(dst_by_src.get(dst, [])):
                res = do_flight(dst, next)
                if len(itinerary) == len(tickets):
                    return
            dst_by_src[src].append(dst)
            itinerary.pop()
        src = "JFK"
        for dst in sorted(dst_by_src[src]):
            do_flight(src, dst)
            if len(itinerary) == len(tickets):
                return ["JFK"] + itinerary


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            ["JFK", "NRT", "JFK", "KUL"],
            Solution().findItinerary([["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]])
        )
        self.assertEqual(
            ["JFK", "MUC", "LHR", "SFO", "SJC"],
            Solution().findItinerary([["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]])
        )
        self.assertEqual(
            ["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"],
            Solution().findItinerary([["JFK", "SFO"], ["JFK", "ATL"], ["SFO", "ATL"], ["ATL", "JFK"], ["ATL", "SFO"]])
        )
