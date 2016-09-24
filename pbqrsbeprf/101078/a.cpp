#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    int addr[100001];
    bool map[100001] = {};
    for (int j = 0; j < k; j++) {
        int n, t;
        cin >> n;
        map[n] = false;
        for (int i = 0; i < n; i++) {
            cin >> t;
            addr[t] = i;
            map[i] = false;
        }
        int last = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            cin >> t;
            map[addr[t]] = true;
            while (map[last]) {
                last++;
            }
            if (last > i) {
                cout << prev + 1 << '-' << last << ' ';
                prev = last;
            }
        }
        cout << endl;
    }
}