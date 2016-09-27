#include <iostream>

using namespace std;

int main() {
    int s, n, sum_up = 0, t, min_up = 0, res = 0;
    cin >> s >> n;
    for (int i = 1; i <= s; i++) {
        cin >> t;
        int down = s + n - sum_up - t - (s - i);
        res = min(res, min_up + down);
        sum_up += t;
        min_up = min(min_up, sum_up - i);
    }
    res = min(res, min_up);
    cout << ((res < 0) ? "NO" : "YES");
    return 0;
}