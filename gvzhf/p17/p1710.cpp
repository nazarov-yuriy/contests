#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define range2(x1, y1, x2, y2) ( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

int main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if (range2(xa, ya, xc, yc) + range2(xb, yb, xc, yc) == range2(xa, ya, xb, yb)) {
        cout << "YES";
    } else if (range2(xb, yb, xc, yc) >= range2(xa, ya, xb, yb)) {
        cout << "YES";
    } else {
        long double l = (range2(xa, ya, xc, yc) + range2(xa, ya, xb, yb) - range2(xb, yb, xc, yc))
                        / sqrt(4 * range2(xa, ya, xc, yc));
        long double lc = sqrt(range2(xa, ya, xc, yc));
        long double xcd = (long double) xa + (xc - xa) * (2 * l - lc) / lc;
        long double ycd = (long double) ya + (yc - ya) * (2 * l - lc) / lc;
        cout << "NO" << endl;
        cout << xa << ' ' << ya << endl;
        cout << xb << ' ' << yb << endl;
        cout << setprecision(15) << xcd << ' ' << setprecision(15) << ycd << endl;
    }
    return 0;
}