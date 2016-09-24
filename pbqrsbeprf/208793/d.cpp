#include <iostream>

using namespace std;

int main() {
    long long int n, x, res = 0;
    cin >> n >> x;
    for (int i = 1; i * i <= x; i++) {
        if (0 == (x % i) && i <= n && x / i <= n) {
            res += 2;
            if (i * i == x) res--;
        }
    }
    cout << res;
    return 0;
}