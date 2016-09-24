#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int r[m][m][4] = {};
    for (int i = 0; i < n; i++) {
        int t[m];
        for (int j = 0; j < m; j++) {
            cin >> t[j];
        }
        for (int j = 0; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                r[j][k][t[j] * 2 + t[k]]++;
            }
        }
    }
    int mi = 1000000000, mi_pos_j = 0, mi_pos_k = 0;
    for (int j = 0; j < m; j++) {
        for (int k = j + 1; k < m; k++) {
            int t = max(max(r[j][k][0], r[j][k][1]), max(r[j][k][2], r[j][k][3]));
            if (t < mi) {
                mi = t;
                mi_pos_j = j;
                mi_pos_k = k;
            }
        }
    }
    cout << mi << endl;
    cout << mi_pos_j + 1 << ' ' << mi_pos_k + 1;
    return 0;
}