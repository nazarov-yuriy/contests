#include <iostream>

using namespace std;

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    int ar[n][m];
    int pos[n * m + 1] = {};
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            cin >> ar[row][col];
        }
    }
    for (int i = 0; i < n * m; ++i) {
        int t;
        cin >> t;
        pos[t] = cnt++;
    }
    for (int col = 0; col < m; ++col) {
        int prev = n * m + 1;
        for (int row = 0; row < n; ++row) {
            int v = ar[row][col];
            if (prev < pos[v]) {
                cout << "NO";
                return 0;
            }
            prev = pos[v];
        }
    }
    cout << "YES";
    return 0;
}
