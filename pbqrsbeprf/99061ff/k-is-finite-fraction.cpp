#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long cd = gcd(a, b);
    a /= cd;
    b /= cd;
    for (long long i = 2; i * i <= b; i++) {
        while (0 == (b % i)) {
            if (c % i) {
                cout << "NO";
                return 0;
            }
            b /= i;
        }
    }
    cout << ((c % b) ? "NO" : "YES");
    return 0;
}
