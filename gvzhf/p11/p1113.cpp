#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    long long int n, m;
    cin >> n >> m;
    long double nd = n, f = 0;
    for (int i = 1; i < 100000000; i++) {
        long double dt = ((long double) m) / (i * 2 - 1);
        if (nd <= dt) {
            f += nd * (i * 2 - 1);
            break;
        } else {
            nd -= dt;
            f += m;
        }
    }
    cout << (long long unsigned int)ceil(f-0.0000000001L);
    return 0;
}