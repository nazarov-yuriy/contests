#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int ma = 0, mb = 0, mc = 0;
    int na = 0, nb = 0, nc = 0;
    for (int i = 0; i < 100000; i++) {
        if (m <= (i + 1) * (i + 1)) {
            ma = i;
            break;
        }
    }
    mb = (m - ma * ma - 1) / 2;
    mc = (2 * ma - (m - ma * ma - 1)) / 2;

    for (int i = 0; i < 100000; i++) {
        if (n <= (i + 1) * (i + 1)) {
            na = i;
            break;
        }
    }
    nb = (n - na * na - 1) / 2;
    nc = (2 * na - (n - na * na - 1)) / 2;

    //cout << ma << ' ' << mb << ' ' << mc << endl;
    //cout << na << ' ' << nb << ' ' << nc << endl;
    cout << abs(ma - na) + abs(mb - nb) + abs(mc - nc);
    return 0;
}