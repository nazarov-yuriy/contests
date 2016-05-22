#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int v, n, min_p = 0;
    long double Tphr, x, t, min_d = 1000000000000.0;
    cin >> v >> Tphr >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> t;
        if ((t + Tphr) * v + x < min_d) {
            min_d = (t + Tphr) * v + x;
            min_p = i;
        }
    }
    cout << setprecision(10) << min_d << ' ' << min_p + 1 << endl;
    return 0;
}