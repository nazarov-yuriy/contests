import unittest
from typing import List


class Solution:
    def divisors(self, x, candidates, candidates_set):
        res = []
        cand_iter = iter(candidates)
        i = next(cand_iter)
        while i * i <= x:
            if x % i == 0 and x // i in candidates_set:
                res.append((i, x // i))
            i = next(cand_iter)
        return res

    def numFactoredBinaryTrees(self, A: List[int]) -> int:
        num_to_divisors = {}
        candidates = sorted(A)
        candidates_set = set(candidates)
        for num in A:
            num_to_divisors[num] = self.divisors(num, candidates, candidates_set)

        # print(num_to_divisors)

        def subtree(x):
            res = 1
            for a, b in num_to_divisors.get(x, []):
                if a == b:
                    res += 1 * subtree(a) * subtree(b)
                else:
                    res += 2 * subtree(a) * subtree(b)
            return res % (10 ** 9 + 7)

        res = 0
        for num in num_to_divisors:
            diff = subtree(num)
            res += diff
            # print(num, diff)
        return res % (10 ** 9 + 7)


class Test(unittest.TestCase):
    def test(self):
        A = [18, 31, 2, 4, 14, 7, 9, 63, 10, 84]
        self.assertEqual(Solution().numFactoredBinaryTrees(A), 17)
        A = [2, 4]
        self.assertEqual(Solution().numFactoredBinaryTrees(A), 3)
        A = [2, 4, 5, 10]
        self.assertEqual(Solution().numFactoredBinaryTrees(A), 7)
        A = [15, 13, 22, 7, 11]
        self.assertEqual(Solution().numFactoredBinaryTrees(A), 5)
        A = [197, 328, 400, 11, 77, 102, 150, 171, 298, 370, 224, 99, 269, 218, 151, 34, 396, 20, 61, 135]
        self.assertEqual(Solution().numFactoredBinaryTrees(A), 21)
        A = [544872450, 716541450, 328215025, 470652580, 262019045, 487748243, 531209232, 663766560, 673902463,
             465597488, 164039885, 53370129, 591625750, 736153225, 674040091, 269312679, 556453098, 485703447,
             358792277, 905118975, 327193963, 651753791, 37957142, 721224382, 253912781, 9341005, 459826924, 931258663,
             286647151, 240832068, 133137614, 225709480, 802907668, 643597836, 909770849, 935519659, 867945249,
             787075558, 801837681, 700838335, 431803442, 12040658, 399935045, 351008062, 122691837, 468472633,
             998831642, 743302217, 178818635, 64364609, 348333498, 544957142, 290114508, 779517733, 604250423,
             267289147, 16941841, 356839463, 579775373, 293311260, 95452397, 567363965, 302476506, 485592993, 573262170,
             401097006, 694651950, 385067644, 70072203, 684345095, 745748837, 654639275, 735195481, 68392807, 808503314,
             240883190, 257296455, 75906333, 703101365, 551043131, 162226956, 63507568, 390593352, 179713171, 512608097,
             314527422, 227444084, 52011254, 249251989, 446716928, 653878023, 447631306, 571313878, 228860214,
             713906705, 685773097, 568020011, 569898493, 201671489, 981281594]
        self.assertEqual(Solution().numFactoredBinaryTrees(A), 100)
