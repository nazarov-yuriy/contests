#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    unsigned int a, b, n, d;
    bool swapped = false;
    cin >> a >> b >> n;
    d = n % gcd(a, b);
    int na = n, nb = n;
    for (int i = 0; i < 4000000; i++) {
        if (na > 0) {
            if (na % b == d) {
                cout << i << ' ' << na / b;
                return 0;
            }
            if (na % (a + b) == d) {
                cout << na / (a + b) + i << ' ' << na / (a + b);
                return 0;
            }
            na -= a;
        }
        if (nb > 0) {
            if (nb % a == d) {
                cout << nb / a << ' ' << i;
                return 0;
            }
            if (nb % (a + b) == d) {
                cout << nb / (a + b) << ' ' << nb / (a + b) + i;
                return 0;
            }
            nb -= b;
        }
    }
    if (a == b) {
        cout << n / a << ' ' << 0;
    } else if (a < b) {
        unsigned int t = a;
        a = b;
        b = t;
        swapped = true;
    }
    unsigned int ca = n / a;
    unsigned int cb = (n - a * ca) / b;
    unsigned int m = n - ca * a - cb * b, mca = ca, mcb = cb;
    while (ca && m > d) {
        ca--;
        cb = (n - a * ca) / b;
        if (n - ca * a - cb * b < m) {
            m = n - ca * a - cb * b;
            mca = ca;
            mcb = cb;
        }
    }
    if (swapped) {
        cout << mcb << ' ' << mca;
    } else {
        cout << mca << ' ' << mcb;
    }
    return 0;
}