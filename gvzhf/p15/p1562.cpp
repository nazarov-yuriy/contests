#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#ifndef M_PI
#define M_PI		3.14159265358979323846	/* pi */
#endif

int main() {
    int n;
    double a, b, pv = 0;
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++) {
        double s = a / n;
        double h = s * (i + 1);
        double v = M_PI * h * h * (a / 2.0 - 1.0 / 3.0 * h);
        cout << setprecision(6) << fixed << ((v - pv) * b / a) << endl;
        pv = v;
    }
    return 0;
}