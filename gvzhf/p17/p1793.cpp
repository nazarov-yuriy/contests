#include <iostream>

using namespace std;

int main() {
    double a, b, d, h;
    cin >> a >> b >> d;
    double r1, R1, r2, R2;
    cin >> r1 >> R1 >> r2 >> R2;
    cin >> h;
    if (b > a) swap(a, b);
    double m1, m2;
    if (d < h) {
        m1 = r1 + (R1 - r1) * d / h;
        m2 = r2 + (R2 - r2) * d / h;
    } else {
        m1 = R1;
        m2 = R2;
    }
    if ((m1 - 0.000001 > b / 2.0) || (m2 - 0.000001 > b / 2.0)) {
        cout << "NO";
    } else {
        double da = a - m1 - m2;
        double db = b - m1 - m2;
        if (((R1 + R2) * (R1 + R2) - 0.000001) > (da * da + db * db)) {
            cout << "NO";
        } else {
            cout << "YES";
        }
    }
    return 0;
}