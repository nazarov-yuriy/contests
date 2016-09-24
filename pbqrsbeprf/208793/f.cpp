#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int pos[n];
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    for (int i = 0; i < n; i++) {
        int mi = 2000000000, ma = 0;
        if (0 < i) {
            mi = min(mi, pos[i] - pos[i - 1]);
            ma = max(ma, pos[i] - pos[0]);
        }
        if (i < n - 1) {
            mi = min(mi, pos[i + 1] - pos[i]);
            ma = max(ma, pos[n - 1] - pos[i]);
        }
        cout << mi << ' ' << ma << endl;
    }
    return 0;
}