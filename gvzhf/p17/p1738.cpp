#include <iostream>

using namespace std;

int rep(int v, int to, int pos) {
    if (pos > v) return 0;
    return to * pos + v % pos + pos * 10 * (v / 10 / pos);
}

int ins(int v, int to, int pos) {
    if (pos > v * 10) return 0;
    return to * pos + v % pos + pos * 10 * (v / pos);
}

int diff(unsigned int a, unsigned int b) {
    return (((a ^ b) & 0xf000) > 0) + (((a ^ b) & 0x0f00) > 0) + (((a ^ b) & 0x00f0) > 0) + (((a ^ b) & 0x000f) > 0);
}

int main() {
    int n;
    unsigned int res[5] = {};
    cin >> n;
    unsigned int vals[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> hex >> vals[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j <= 9; j++) {
            int rep1 = rep(i, j, 1);
            if (i < rep1 && rep1 <= n) res[diff(vals[i], vals[rep1])]++;
            int rep2 = rep(i, j, 10);
            if (i < rep2 && rep2 <= n) res[diff(vals[i], vals[rep2])]++;
            int rep3 = rep(i, j, 100);
            if (i < rep3 && rep3 <= n) res[diff(vals[i], vals[rep3])]++;
            int rep4 = rep(i, j, 1000);
            if (i < rep4 && rep4 <= n) res[diff(vals[i], vals[rep4])]++;
            int rep5 = rep(i, j, 10000);
            if (i < rep5 && rep5 <= n) res[diff(vals[i], vals[rep5])]++;

            int ins1 = ins(i, j, 1);
            if (i < ins1 && ins1 <= n)
                res[diff(vals[i], vals[ins1])]++;
            int ins2 = ins(i, j, 10);
            if (i < ins2 && ins2 <= n && ins1 != ins2)
                res[diff(vals[i], vals[ins2])]++;
            int ins3 = ins(i, j, 100);
            if (i < ins3 && ins3 <= n && ins1 != ins3 && ins2 != ins3)
                res[diff(vals[i], vals[ins3])]++;
            int ins4 = ins(i, j, 1000);
            if (i < ins4 && ins4 <= n && ins1 != ins4 && ins2 != ins4 && ins3 != ins4)
                res[diff(vals[i], vals[ins4])]++;
            int ins5 = ins(i, j, 10000);
            if (i < ins5 && ins5 <= n && ins1 != ins5 && ins2 != ins5 && ins3 != ins5 && ins4 != ins5)
                res[diff(vals[i], vals[ins5])]++;
        }
    }
    cout << res[1] << ' ' << res[2] << ' ' << res[3] << ' ' << res[4];
    return 0;
}