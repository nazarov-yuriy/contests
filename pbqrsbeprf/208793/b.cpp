#include <iostream>

using namespace std;

int main() {
    long long int n, m, last, t, res = 0;
    cin >> n >> m;
    cin >> last;
    res = last - 1;
    for (int i = 1; i < m; i++) {
        cin >> t;
        if (t >= last)
            res += t - last;
        else
            res += n + t - last;
        last = t;
    }
    cout << res;
    return 0;
}