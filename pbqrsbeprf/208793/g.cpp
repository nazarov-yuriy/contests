#include <iostream>

using namespace std;

int main() {
    int n, ph = -1, pm = -1, cnt = 0, res = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h, m;
        cin >> h >> m;
        if (ph == h && pm == m) {
            cnt++;
            res = max(res, cnt);
        } else {
            cnt = 1;
        }
        ph = h;
        pm = m;
    }
    cout << res;
    return 0;
}