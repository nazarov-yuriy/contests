#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long double xp, yp, xd, yd, res;
    cin >> xp >> yp;
    cin >> xd >> yd;
    res = 0.916297857297023 * ((xp - xd) * (xp - xd) + (yp - yd) * (yp - yd));
    cout << setprecision(15) << res;
    return 0;
}