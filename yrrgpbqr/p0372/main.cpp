#include <vector>

using namespace std;

class Solution {
private:
    int modulo = 1337;
public:
    int superPow(int a, vector<int>& b) {
        int multiplier = a % modulo;
        int res = 1;
        for (auto pow = b.rbegin(); pow != b.rend(); ++pow) {
            for (int i = 0; i < *pow; ++i) {
                res = (res * multiplier) % modulo;
            }
            int next_multiplier = 1;
            for (int i = 0; i < 10; ++i) {
                next_multiplier = (next_multiplier * multiplier) % modulo;
            }
            multiplier = next_multiplier;
        }
        return res;
    }
};

#include <cassert>

int main() {
    {
        int a = 2;
        vector<int> b = {3};
        assert(Solution().superPow(a, b) == 8);
    }
    {
        int a = 1;
        vector<int> b = {4,3,3,8,5,2};
        assert(Solution().superPow(a, b) == 1);
    }
    {
        int a = 2147483647;
        vector<int> b = {2,0,0};
        assert(Solution().superPow(a, b) == 1198);
    }
    return 0;
}