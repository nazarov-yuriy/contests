#include <iostream>
#include <cmath>

#ifndef M_PI
# define M_PI		3.14159265358979323846	/* pi */
#endif

using namespace std;

struct point {
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    point p[n];
    double a[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    double res = 0;
    for (int i = 0; i < n; i++) {
        a[i] = atan2(p[(i + 1) % n].y - p[i].y, p[(i + 1) % n].x - p[i].x);
    }
    for (int i = 0; i < n; i++) {
        double da = fmod(a[(i + 1) % n] - a[i] + 3.0 * M_PI, 2.0 * M_PI) - M_PI;
        res += da;
    }
    if (res < 0) {
        cout << "cw";
    } else {
        cout << "ccw";
    }
    return 0;
}