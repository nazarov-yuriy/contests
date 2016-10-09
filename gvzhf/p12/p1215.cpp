#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    double x, y;
    int n;
    cin >> x >> y >> n;
    double xs[n], ys[n], sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> xs[i] >> ys[i];
    }
    for (int i = 2; i < n; i++) {
        double a = dist(xs[0], ys[0], xs[i], ys[i]);
        double b = dist(xs[0], ys[0], xs[i - 1], ys[i - 1]);
        double c = dist(xs[i], ys[i], xs[i - 1], ys[i - 1]);
        double s = sqrt((a + b + c) * (a + b - c) * (a - b + c) * (b + c - a)) / 4.0;
        sm += s;
    }
    double res = 1000000;
    for (int i = 0; i < n; i++) {
        res = min(res, dist(x, y, xs[i], ys[i]));
        double a = dist(x, y, xs[i], ys[i]);
        double b = dist(x, y, xs[(i + 1) % n], ys[(i + 1) % n]);
        double c = dist(xs[i], ys[i], xs[(i + 1) % n], ys[(i + 1) % n]);
        double s = sqrt((a + b + c) * (a + b - c) * (a - b + c) * (b + c - a)) / 4.0;
        sm -= s;
        if ((a * a <= b * b + c * c) && (b * b <= a * a + c * c)) {
            res = min(res, 2.0 * s / c);
        }
    }
    if (abs(sm) <= 0.0001)
        cout << "0.000";
    else
        cout << setprecision(3) << fixed << (res * 2.0);
    return 0;
}