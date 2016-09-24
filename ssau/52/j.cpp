#include <iostream>

using namespace std;

int main() {
    long long int n, res = 0;
    cin >> n;
    long long int a[n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    a[n + 1] = 0;
    for (int i = 1; i <= n + 1; i++) {
        res += abs(a[i] - a[i - 1]);
    }
    cout << res / 2;
    return 0;
}