#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double da, db;
    long long int n, a, b, max_cnt_r = 0, max_cnt_k = 0, max_p_r = 0, max_p_k = 0, max_p = 0;
    cin >> da >> db >> n;
    a = llround(da * 100.0);
    b = llround(db * 100.0);
    for (long long int i = 1; i <= n; i++) {
        if (a * i - i * i * 100 > max_p_r) {
            max_p_r = a * i - i * i * 100;
            max_cnt_r = i;
        }
        if (b * i - i * i * 100 > max_p_k) {
            max_p_k = b * i - i * i * 100;
            max_cnt_k = i;
        }
    }
    if (max_cnt_k + max_cnt_r <= n) {
        cout << setprecision(2) << fixed << (max_p_k + max_p_r) / 100.0 << endl;
        cout << max_cnt_r << ' ' << max_cnt_k;
    } else {
        for (long long int r = 0; r <= n; r++) {
            long long int k = n - r;
            if (r * a + k * b - r * r * 100 - k * k * 100 > max_p) {
                max_p = r * a + k * b - r * r * 100 - k * k * 100;
                max_cnt_k = k;
                max_cnt_r = r;
            }
        }
        cout << setprecision(2) << fixed << max_p / 100.0 << endl;
        cout << max_cnt_r << ' ' << max_cnt_k;
    }
    return 0;
}