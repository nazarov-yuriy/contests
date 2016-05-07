#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int max_left = 0, min_right = n - 1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v) {
            int t = u;
            u = v;
            v = t;
        }
        max_left = max(u, max_left);
        min_right = min(v, min_right);
    }
    if (min_right > max_left) {
        cout << min_right - max_left;
    } else {
        cout << 0;
    }
    return 0;
}