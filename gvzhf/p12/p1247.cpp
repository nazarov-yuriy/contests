#include <iostream>

using namespace std;

int main() {
    int n, useless_n, sum_up = 0, sum_down = 0;
    cin >> n >> useless_n;
    int inp[n], up[n] = {}, down[n] = {};
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }
    for (int i = 1; i < n; i++) {
        sum_up += inp[i - 1];
        up[i] = min(up[i - 1], sum_up - i);
    }
    for (int i = n - 2; i >= 0; i--) {
        sum_down += inp[i + 1];
        down[i] = min(down[i + 1], sum_down - (n - 1 - i));
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = min(res, up[i] + down[i]);
    }
    cout << ((res < 0) ? "NO" : "YES");
    return 0;
}