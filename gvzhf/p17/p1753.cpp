#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    long double h, H, L, x, m = 0.0;
    cin >> h >> H >> L;
    for (int i = 0; i <= 5000000; i++) {
        x = H * i / 10000000.0;
        long double r = sqrt(h * h + x * x);
        long double l = x * H / 2.0 / r - x;
        m = max(m, l);
    }
    cout << setprecision(15) << m;
    return 0;
}