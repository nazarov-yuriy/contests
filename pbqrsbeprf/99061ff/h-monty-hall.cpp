#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m, k, c;
    double res = 0;
    cin >> n >> k >> m;
    c = min(k, n - m - k);
    res = ((double) c) * (n - k) / (n - m - k) / n;
    res += ((double) k - c) / n;
    cout << fixed << setprecision(12) << res;
    return 0;
}
