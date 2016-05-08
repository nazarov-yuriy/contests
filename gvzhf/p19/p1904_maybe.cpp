#include <iostream>

using namespace std;

#define SZ 16384

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[n - 1 - i];
    }
    int map[2 * SZ] = {};
    map[SZ] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = -SZ + 1009; j < SZ - 1009; j++) {
            map[SZ + j + a[i]] |= (map[SZ + j] & (1 << i)) << 1;
            map[SZ - j - 1 + a[i]] |= (map[SZ + j] & (1 << i)) << 1;
        }
    }
    bool in = false;
    for (int j = -SZ; j < SZ; j++) {
        if (in) {
            if (!(map[SZ + j] & (1 << n))) {
                cout << j << endl;
                in = false;
            }
        } else {
            if (map[SZ + j] & (1 << n)) {
                cout << j << ' ';
                in = true;
            }
        }
    }
    return 0;
}