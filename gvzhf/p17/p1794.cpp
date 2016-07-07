#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt[n] = {};
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        cnt[(t + n - i) % n]++;
    }
    int max_pos = 0, max_val = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] > max_val) {
            max_val = cnt[i];
            max_pos = i;
        }
    }
    cout << (n - max_pos) % n + 1;
    return 0;
}