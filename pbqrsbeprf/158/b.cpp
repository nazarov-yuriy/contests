#include <iostream>

using namespace std;

int main() {
    int n, c[5] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        c[t]++;
    }
    int cnt = c[4] + c[3];
    c[1] = max(0, c[1] - c[3]);
    cnt += (c[2] + 1) / 2;
    if (c[2] % 2) c[1] = max(0, c[1] - 2);
    cnt += (c[1] + 3) / 4;
    cout << cnt;
    return 0;
}