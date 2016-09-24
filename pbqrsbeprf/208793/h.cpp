#include <iostream>

using namespace std;

int main() {
    int n, m, pos = 1;
    cin >> n;
    int res[1000009];
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            res[pos++] = i;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        cout << res[t] << ' ';
    }
    return 0;
}