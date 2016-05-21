#include <iostream>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int len[n + 1] = {};
    len[s] = 1;
    bool changed = true;
    while (changed) {
        changed = false;
        for (int f = s; f <= n; f++) {
            if (len[f]) {
                for (int t = f + 1; t <= n; t++) {
                    if (0 == (t * 100) % f && len[t] <= len[f]) {
                        len[t] = len[f] + 1;
                        changed = true;
                    }
                }
            }
        }
    }
    int max_len = 0;
    for (int i = 0; i <= n; i++) {
        max_len = max(max_len, len[i]);
    }
    cout << max_len;
    return 0;
}