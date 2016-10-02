#include <iostream>

using namespace std;

int main() {
    int n, m, k, t, prev_weight = 0, res = 0, pos = 0;
    cin >> n >> m >> k;
    int prev_weights[n + 1] = {}, dec_tos[n + 1] = {};
    for (int i = 1; i <= n; i++) {
        cin >> t;
        prev_weight += t;
        prev_weights[i] = prev_weight;
    }
    int dec_to = n;
    for (int i = n; i >= 1; i--) {
        while (prev_weights[i] - prev_weights[dec_to] <= k && dec_to) {
            dec_to--;
        }
        dec_tos[i] = dec_to;
    }
    int prev_t = 0;
    for (int i = 0; i < m; i++) {
        cin >> t;
        pos += (t - prev_t) - 1;
        res += (t - prev_t);
        if (pos >= n) {
            pos++;
            break;
        }
        prev_t = t;
        pos = dec_tos[pos];
    }
    cout << res + n - pos;
    return 0;
}