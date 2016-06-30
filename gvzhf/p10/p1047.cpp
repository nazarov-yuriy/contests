#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    long double t;
    long long int c[3005] = {}, a0, an1, sumc;
    int n;
    cin >> n;
    cin >> t;
    a0 = llround(100.0 * t);
    cin >> t;
    an1 = llround(100.0 * t);
    for (int i = 0; i < n; i++) {
        cin >> t;
        c[i] = llround(100.0 * t);
    }
    sumc = -an1;
    for (int i = n - 1; i >= 0; i--) {
        sumc = c[i] * 2 * (n - i) + sumc;
    }
    t = -a0 * n + sumc;
    t /= -(n + 1);
    cout << fixed << setprecision(2) << t / 100.0;
    return 0;
}