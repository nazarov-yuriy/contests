#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
        long long int a, b, c;
        cin >> a >> b >> c;
        long long int u, d;
        u = (a * b + c * c - 1) / (c * c);
        d = (a * b) / (c * c);
        if (abs(u * c * c - a * b) < abs(d * c * c - a * b)) {
            if (u == 0)
                cout << c * c << endl;
            else
                cout << u * c * c << endl;
        } else {
            if (d == 0)
                cout << c * c << endl;
            else
                cout << d * c * c << endl;
        }
    }
    return 0;
}