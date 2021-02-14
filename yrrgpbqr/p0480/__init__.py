import unittest
from typing import List
import heapq
import random


class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        if k <= 1:
            return nums
        lh, uh = [], []  # lh smaller
        l_removed, u_removed = 0, 0
        for i, num in enumerate(nums[:k]):
            heapq.heappush(uh, (num, i))
        while len(uh) - len(lh) > 1:
            num, i = heapq.heappop(uh)
            heapq.heappush(lh, (-num, i))
        # print(lh, uh)
        res = []
        if len(lh) == len(uh):
            median = (-lh[0][0] + uh[0][0]) / 2
        else:
            median = uh[0][0]
        res.append(median)
        for l, r in zip(range(len(nums)), range(k, len(nums))):
            to_add = nums[r]
            if to_add >= median:
                heapq.heappush(uh, (to_add, r))
            else:
                heapq.heappush(lh, (-to_add, r))
            to_remove = nums[l]
            # print(f"to_remove={to_remove}, median={median}, lh={lh}, uh={uh}")
            if to_remove == -lh[0][0] and to_remove == uh[0][0]:
                if lh[0][1] < uh[0][1]:
                    l_removed += 1
                else:
                    u_removed += 1
            elif to_remove >= median:
                u_removed += 1
                # print("uh", uh[0], "lh", lh[0])
            else:
                l_removed += 1
                # print("lh", lh[0], "uh", uh[0])
            if (len(uh) - u_removed) - (len(lh) - l_removed) > 1:
                num, i = heapq.heappop(uh)
                heapq.heappush(lh, (-num, i))
            elif (len(lh) - l_removed) - (len(uh) - u_removed) > 0:
                num, i = heapq.heappop(lh)
                heapq.heappush(uh, (-num, i))
            # print("b", l, len(lh), l_removed, len(uh), u_removed)
            while len(lh) > 0 and lh[0][1] <= l:
                heapq.heappop(lh)
                l_removed -= 1
            while len(uh) > 0 and uh[0][1] <= l:
                heapq.heappop(uh)
                u_removed -= 1
            # print("a", l, len(lh), l_removed, len(uh), u_removed)
            if (len(uh) - u_removed) == (len(lh) - l_removed):
                median = (-lh[0][0] + uh[0][0]) / 2
            else:
                median = uh[0][0]
            res.append(median)
        return res

    def slowMedianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        return [(sorted(nums[l:r])[k//2] + sorted(nums[l:r])[(k-1)//2]) / 2 for l, r in zip(range(len(nums)), range(k, len(nums)+1))]


class Test(unittest.TestCase):
    def test(self):
        nums = [6156, 8470, 1809, 7021, 9230, 7308, 207, 3104, 7091, 1579, 2833, 161, 9266, 4807, 1637, 1659, 4896, 1697, 6493, 9758, 5086, 5800, 6528, 9387, 265, 1964, 6629, 6645, 4502, 273, 2952, 8845, 9613, 9525, 7992, 3158, 7992, 1699, 7224, 6959, 157, 522, 9046, 3688, 8493, 5830, 9492, 7071, 4535, 5952, 5444, 6038, 6961, 9586, 5724, 8761, 4664, 3137, 368, 4598, 5796, 8896, 8896, 526, 5451, 3188, 8779, 5047, 3428, 9590, 6791, 3549, 2177]
        k = 2
        out = [7313.0, 5139.5, 4415.0, 8125.5, 8269.0, 3757.5, 1655.5, 5097.5, 4335.0, 2206.0, 1497.0, 4713.5, 7036.5, 3222.0, 1648.0, 3277.5, 3296.5, 4095.0, 8125.5, 7422.0, 5443.0, 6164.0, 7957.5, 4826.0, 1114.5, 4296.5, 6637.0, 5573.5, 2387.5, 1612.5, 5898.5, 9229.0, 9569.0, 8758.5, 5575.0, 5575.0, 4845.5, 4461.5, 7091.5, 3558.0, 339.5, 4784.0, 6367.0, 6090.5, 7161.5, 7661.0, 8281.5, 5803.0, 5243.5, 5698.0, 5741.0, 6499.5, 8273.5, 7655.0, 7242.5, 6712.5, 3900.5, 1752.5, 2483.0, 5197.0, 7346.0, 8896.0, 4711.0, 2988.5, 4319.5, 5983.5, 6913.0, 4237.5, 6509.0, 8190.5, 5170.0, 2863.0]
        res = Solution().medianSlidingWindow(nums, k)
        self.assertEqual(res, out)

        nums = [1, 3, -1, -3, 5, 3, 6, 7]
        k = 3
        out = [1, -1, -1, 3, 5, 6]
        res = Solution().medianSlidingWindow(nums, k)
        self.assertEqual(res, out)

        nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
        k = 5
        out = [3, 4, 5, 6, 7, 8, 9, 10]
        res = Solution().slowMedianSlidingWindow(nums, k)
        self.assertEqual(res, out)

        for i in range(1, 100):
            for k in range(1, i+1):
                nums = [random.randint(0, 10000) for _ in range(i)]
                try:
                    res = Solution().medianSlidingWindow(nums, k)
                except:
                    print(nums, k)
                expected = res = Solution().slowMedianSlidingWindow(nums, k)
                if res != expected:
                    print(nums, k)
                self.assertEqual(res, expected)
