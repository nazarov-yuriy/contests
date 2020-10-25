import unittest


class Solution:
    def clumsy_block(self, nums):
        res = nums[0]
        if len(nums) > 1:
            res *= nums[1]
        if len(nums) > 2:
            res //= nums[2]
        if len(nums) > 3:
            res += - nums[3]
        return - res

    def clumsy(self, N: int) -> int:
        numbers = list(reversed(range(1, N + 1)))
        res = -2 * self.clumsy_block(numbers[:3])
        for pos in range(0, N, 4):
            res += self.clumsy_block(numbers[pos:pos + 4])

        return res


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().clumsy(10), 12)
        self.assertEqual(Solution().clumsy(4), 7)
        self.assertEqual(Solution().clumsy(5), 7)  # 5 * 4 / 3 + 2 - 1
        self.assertEqual(Solution().clumsy(1), 1)
        self.assertEqual(Solution().clumsy(10000), 10001)
