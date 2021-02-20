import unittest
from typing import List
from itertools import chain, islice

def swap(A, range1, range2):
    assert next(iter(reversed(range1))) == next(iter(range2)) - 1
    #rev range1
    for l, r in zip(range1, reversed(range1)):
        if l >= r:
            break
        else:
            A[l], A[r] = A[r], A[l]
    #rev range2
    for l, r in zip(range2, reversed(range2)):
        if l >= r:
            break
        else:
            A[l], A[r] = A[r], A[l]
    #rev total
    range_total = range(next(iter(range1)), next(iter(reversed(range2))) + 1)
    for l, r in zip(range_total, reversed(range_total)):
        if l >= r:
            break
        else:
            A[l], A[r] = A[r], A[l]


def transpose(A):
    n = len(A)
    group = 1
    while 2 * group < n:
        start = 0
        while start < n:
            range1 = range(start + group * 1, start + group * 2)
            last_group = min(group, (n - (start + group * 2)) // 2)
            range2 = range(start + group * 2, start + group * 2 + last_group)
            if len(range2):
                swap(A, range1, range2)
            start += 4 * group
        group *= 2


class Test(unittest.TestCase):
    def test(self):
        for n in range(1, 1000):
            A = list(
                chain(
                    *zip(
                        ["a%03d" %i for i in range(n)],
                        ["b%03d" %i for i in range(n)]
                    )
                )
            )
            transpose(A)
            self.assertEqual(sorted(A), A)
