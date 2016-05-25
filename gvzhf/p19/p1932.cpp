#include <iostream>

using namespace std;

unsigned int nn1(unsigned int v) {
    return v * (v - 1) / 2;
}

int main() {
    unsigned int cnt1[4][4096] = {};
    unsigned int cnt2[6][256] = {};
    unsigned int cnt3[4][16] = {};
    unsigned int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> hex >> t;
        cnt1[0][t & 0xfff]++;
        cnt1[1][t & 0xf | ((t & 0xff00) >> 4)]++;
        cnt1[2][t & 0xff | ((t & 0xf000) >> 4)]++;
        cnt1[3][t >> 4]++;

        cnt2[0][(((t >> 4) & 0xf) << 4) | (((t >> 0) & 0xf))]++;
        cnt2[1][(((t >> 8) & 0xf) << 4) | (((t >> 0) & 0xf))]++;
        cnt2[2][(((t >> 12) & 0xf) << 4) | (((t >> 0) & 0xf))]++;
        cnt2[3][(((t >> 8) & 0xf) << 4) | (((t >> 4) & 0xf))]++;
        cnt2[4][(((t >> 12) & 0xf) << 4) | (((t >> 4) & 0xf))]++;
        cnt2[5][(((t >> 12) & 0xf) << 4) | (((t >> 8) & 0xf))]++;

        cnt3[0][(t >> 0) & 0xf]++;
        cnt3[1][(t >> 4) & 0xf]++;
        cnt3[2][(t >> 8) & 0xf]++;
        cnt3[3][(t >> 12) & 0xf]++;
    }
    unsigned int d1[4] = {}, d2[6] = {}, d3[4] = {}, d4 = n * (n - 1) / 2;
    for (int i = 0; i < 4096; i++) {
        d1[0] += nn1(cnt1[0][i]);
        d1[1] += nn1(cnt1[1][i]);
        d1[2] += nn1(cnt1[2][i]);
        d1[3] += nn1(cnt1[3][i]);
    }
    for (int i = 0; i < 256; i++) {
        d2[0] += nn1(cnt2[0][i]);
        d2[1] += nn1(cnt2[1][i]);
        d2[2] += nn1(cnt2[2][i]);
        d2[3] += nn1(cnt2[3][i]);
        d2[4] += nn1(cnt2[4][i]);
        d2[5] += nn1(cnt2[5][i]);
    }
    for (int i = 0; i < 16; i++) {
        d3[0] += nn1(cnt3[0][i]);
        d3[1] += nn1(cnt3[1][i]);
        d3[2] += nn1(cnt3[2][i]);
        d3[3] += nn1(cnt3[3][i]);
    }
    d2[0] -= d1[0] + d1[1];
    d2[1] -= d1[0] + d1[2];
    d2[2] -= d1[1] + d1[2];
    d2[3] -= d1[0] + d1[3];
    d2[4] -= d1[1] + d1[3];
    d2[5] -= d1[2] + d1[3];

    d3[0] -= d2[0] + d2[1] + d2[2] + d1[0] + d1[1] + d1[2];
    d3[1] -= d2[0] + d2[3] + d2[4] + d1[0] + d1[1] + d1[3];
    d3[2] -= d2[1] + d2[3] + d2[5] + d1[0] + d1[2] + d1[3];
    d3[3] -= d2[2] + d2[4] + d2[5] + d1[1] + d1[2] + d1[3];

    d4 -= d1[0] + d1[1] + d1[2] + d1[3] + d2[0] + d2[1] + d2[2] + d2[3] + d2[4] + d2[5] + d3[0] + d3[1] + d3[2] + d3[3];
    cout << d1[0] + d1[1] + d1[2] + d1[3] << ' ';
    cout << d2[0] + d2[1] + d2[2] + d2[3] + d2[4] + d2[5] << ' ';
    cout << d3[0] + d3[1] + d3[2] + d3[3] << ' ' << d4;
    return 0;
}