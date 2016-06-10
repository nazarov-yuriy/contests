#include <iostream>

using namespace std;

unsigned int cnt1(unsigned int bit, unsigned int to) {
    unsigned int res = (to / (2 * bit)) * bit;
    to %= 2 * bit;
    if (to > bit) res += to % bit;
    return res;
}

unsigned int cnt0(unsigned int bit, unsigned int to) {
    return to - cnt1(bit, to);
}

int main() {
    unsigned int l, r;
    cin >> l >> r;
    unsigned int res = 0;
    for (unsigned int i = 1; i != 2 * 1024 * 1024 * 1024; i *= 2) {
        unsigned int c1 = cnt1(i, r + 1) - cnt1(i, l);
        unsigned int c0 = cnt0(i, r + 1) - cnt0(i, l);
        if (c1 > c0) {
            res |= i;
        }
    }
    cout << res;
    return 0;
}