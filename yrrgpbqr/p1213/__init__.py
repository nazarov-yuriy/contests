import unittest
from typing import List


class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        p1, p2, p3 = 0, 0, 0
        res = []
        while p1 < len(arr1) and p2 < len(arr2) and p3 < len(arr3):
            if arr1[p1] == arr2[p2] and arr2[p2] == arr3[p3]:
                res.append(arr1[p1])
                p1 += 1
                p2 += 1
                p3 += 1
            else:
                if arr1[p1] <= arr2[p2] and arr1[p1] <= arr3[p3]:
                    p1 += 1
                elif arr2[p2] <= arr1[p1] and arr2[p2] <= arr3[p3]:
                    p2 += 1
                elif arr3[p3] <= arr1[p1] and arr3[p3] <= arr2[p2]:
                    p3 += 1
                else:
                    assert False
        return res


class Test(unittest.TestCase):
    def test(self):
        arr1 = [1, 2, 3, 4, 5]
        arr2 = [1, 2, 5, 7, 9]
        arr3 = [1, 3, 4, 5, 8]
        out = [1, 5]
        self.assertEqual(Solution().arraysIntersection(arr1, arr2, arr3), out)
        arr1 = [197,418,523,876,1356]
        arr2 = [501,880,1593,1710,1870]
        arr3 = [521,682,1337,1395,1764]
        out = []
        self.assertEqual(Solution().arraysIntersection(arr1, arr2, arr3), out)
