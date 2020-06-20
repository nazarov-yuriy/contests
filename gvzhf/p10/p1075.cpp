#include <iostream>

#define _USE_MATH_DEFINES

#include <cmath>

using namespace std;

#define EPS 0.00000001

double clampacos(double x) {
    return acos(min(1.0, max(-1.0, x)));
}

double clampasin(double x) {
    return asin(min(1.0, max(-1.0, x)));
}

int main() {
    double xa;
    double ya;
    double za;
    double xb;
    double yb;
    double zb;
    double xc;
    double yc;
    double zc;
    double r;
    cin >> xa >> ya >> za >> xb >> yb >> zb >> xc >> yc >> zc >> r;
    double ab = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb) + (za - zb) * (za - zb));
    double ac = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc) + (za - zc) * (za - zc));
    double bc = sqrt((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb) + (zc - zb) * (zc - zb));
    double p = (ab + bc + ac) / 2.0;
    double s = sqrt(p * (p - ab) * (p - ac) * (p - bc));
    double aac = clampacos((ac * ac + ab * ab - bc * bc) / (2.0 * ab * ac));
    double abc = clampacos((bc * bc + ab * ab - ac * ac) / (2.0 * ab * bc));

    if (2.0 * s / ab > r || aac > M_PI / 2.0 - EPS || abc > M_PI / 2.0 - EPS ||
        (s < 0.000000001 && (ac > ab || bc > ab))) {
        cout << (round(100.0 * ab) / 100.0) << endl;
    } else {
        double al = clampasin(r / ac) - clampacos((ac * ac + ab * ab - bc * bc) / (2.0 * ab * ac));
        double bl = clampasin(r / bc) - clampacos((bc * bc + ab * ab - ac * ac) / (2.0 * ab * bc));
        double t = (al + bl) * r + sqrt(ac * ac - r * r) + sqrt(bc * bc - r * r);
        cout << (round(100.0 * t) / 100.0) << endl;
    }
    return 0;
}