#include <iostream>

using namespace std;

#define N 470
int main() {
    int n;
    cin >> n;
    getchar();
    uint64_t val[N] = {0xffffffffffffffffLL, 0};
    for (int i = 0; i < n; i++) {
        char c;
        while ('<' > (c = (char) getchar())) { }
        val[i / 64 + 1] |= ((uint64_t) (c == '<')) << (i % 64);
    }
    int res = 0;
    int inc = 0;
    do {
        uint64_t prev = 0;
        inc = 0;
        for (int i = N - 1; i > 0; i--) {
            uint64_t c = val[i] & ((~val[i]) << 1 | (~val[i - 1]) >> 63);
            inc += __builtin_popcountll(c);
            val[i] ^= c;
            val[i] ^= c >> 1;
            val[i] ^= prev << 63;
            prev = c;
        }
        res += inc;
    } while (inc);
    cout << res;
    return 0;
}