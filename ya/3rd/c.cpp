#include <iostream>

using namespace std;

int main() {
    long long int n, m, oldm, ci;
    long long int res = 0;
    cin >> n >> m;
    long long int a[n], b[n], c[n], sum_b[n + 1] = {}, need_m[n + 1] = {};
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        sum_b[i + 1] = sum_b[i] + b[i];
        need_m[i + 1] = max(need_m[i], a[i] - sum_b[i]);
    }
    while (true) {
        oldm = m;
        ci = 0;
        for (int i = 65536; i > 0; i >>= 1) {
            if (ci + i < n && m > need_m[ci + i + 1]) ci += i;
        }
        if (m > need_m[ci + 1]) ci++;
        if (ci == n) {
            cout << res + n;
            return 0;
        }
        m = max(0LL, m + sum_b[ci] - c[ci]);
        res += ci + 1;
        if (oldm == m) {
            cout << -1;
            return 0;
        }
    }
    return 0;
}