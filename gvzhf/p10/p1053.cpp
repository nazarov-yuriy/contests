#include <iostream>

using namespace std;

long long int eucl(long long int a, long long int b) {
    if (!a) return b;
    if (!b) return a;
    if (a == b) {
        return a;
    } else if (a > b) {
        return eucl(a % b, b);
    } else {
        return eucl(a, b % a);
    }
}

int main() {
    long long int n, res, t;
    cin >> n;
    cin >> res;
    for (int i = 1; i < n; i++) {
        cin >> t;
        res = eucl(res, t);
    }
    cout << res;
    return 0;
}