#include <iostream>

using namespace std;

__int128_t pow(long long unsigned int val, long long unsigned int p, long long unsigned int mod) {
    __int128_t res = 1, mult = val;
    for (int i = 0; i < 63; i++) {
        if (p & (1LL << i)) res = (res * mult) % mod;
        mult = (mult * mult) % mod;
    }
    return (res % mod);
}

int main() {
    long long unsigned int n, k, m, res;
    cin >> n >> k >> m;
    res = (pow(k - 1, (n + 1) / 2, m) * pow(k, (n) / 2, m)) % (__int128_t) m;
    cout << res;
    return 0;
}