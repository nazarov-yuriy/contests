class Solution {
private:
    int bits = 32;
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        for (int shift = 0; shift < bits; shift++) {
            int bit_a = a & (1 << shift);
            int bit_b = b & (1 << shift);
            int bit_carry = carry << shift;
            res |= bit_a ^ bit_b ^ bit_carry;
            carry = ((bit_a & bit_b) | (bit_a & bit_carry) | (bit_b & bit_carry)) >> shift;
        }
        return res;
    }
};

#include <cassert>

int main() {
    assert(Solution().getSum(1, 2) == 3);
    assert(Solution().getSum(100, 200) == 300);
    assert(Solution().getSum(2, -2) == 0);
    assert(Solution().getSum(-2, -2) == -4);
    assert(Solution().getSum(-1000000000, -1000000000) == -2000000000);
    return 0;
}