#include <iostream>

using namespace std;

int n, max_v = 0, g_ms = 2000000000, a[8], w[40] = {1};

void rec(int deep, int bills) {
    if (w[deep] * 2 > max_v) {
        int sum = bills;
        for (int j = 0; j < n; j++) {
            sum += a[j] / w[deep];
        }
        if (sum < g_ms) g_ms = sum;
    } else {
        for (int mul = 2; mul * w[deep] <= max_v; mul++) {
            w[deep + 1] = w[deep] * mul;
            int new_bills = bills;
            for (int i = 0; i < n; i++) {
                new_bills += (a[i] % w[deep + 1]) / w[deep];
                if (!(new_bills < g_ms)) break;
            }
            if (new_bills < g_ms) rec(deep + 1, new_bills);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_v = max(max_v, a[i]);
    }
    rec(0, 0);
    cout << g_ms;
    return 0;
}