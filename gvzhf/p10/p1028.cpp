#include <iostream>

using namespace std;

int main() {
    int cnt[32001] = {}, scnt[256] = {}, res[15001] = {};
    int n, prev_y = -1, prev_x = 0, c = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y == prev_y) {
            for (int j = prev_x; j < x; j++) {
                if (0 == (j % 256) && j + 256 < x) {
                    scnt[j / 256] += c;
                    j += 256 - 1;
                } else {
                    cnt[j] += c;
                }
            }
            prev_x = x;
            c++;
        } else {
            for (int j = prev_x; j <= 32000; j++) {
                if (0 == (j % 256) && j + 256 < 32000) {
                    scnt[j / 256] += c;
                    j += 256 - 1;
                } else {
                    cnt[j] += c;
                }
            }
            c = 1;
            prev_y = y;
            prev_x = x;
        }
        res[cnt[x] + scnt[x / 256] + c - 1]++;
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
    return 0;
}