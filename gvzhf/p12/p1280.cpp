#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    int seq[m][2];
    int pos[n+1];
    for (int i = 0; i < m; i++) {
        cin >> seq[i][0] >> seq[i][1];
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        pos[t] = i;
    }
    for (int i = 0; i < m; i++) {
        if (pos[seq[i][0]] > pos[seq[i][1]]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}