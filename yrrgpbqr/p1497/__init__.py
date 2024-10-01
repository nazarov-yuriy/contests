import unittest
from typing import List


class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        from collections import Counter
        modulus_count = Counter(x % k for x in arr)
        if modulus_count[0] % 2 != 0:
            return False
        for i in range(1, k):
            if i == k - i:
                if modulus_count[i] % 2 != 0:
                    return False
            elif modulus_count[i] != modulus_count[k - i]:
                return False
        return True


class Test(unittest.TestCase):
    def test(self):
        # Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
        # Output: true
        assert Solution().canArrange([1, 2, 3, 4, 5, 10, 6, 7, 8, 9], 5)
        # Input: arr = [1,2,3,4,5,6], k = 7
        # Output: true
        assert Solution().canArrange([1, 2, 3, 4, 5, 6], 7)
        # Input: arr = [1,2,3,4,5,6], k = 10
        # Output: false
        assert not Solution().canArrange([1, 2, 3, 4, 5, 6], 10)
