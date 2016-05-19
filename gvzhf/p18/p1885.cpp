#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long double h, t, v, x;
    cin >> h >> t >> v >> x;
    cout << setprecision(10) << max(t - (t*v - h)/(v-x), (long double)0) << ' ' << setprecision(10) << min(t, h/x);
    return 0;
}