#include <iostream>

using namespace std;

int max_v = 0, n;
int w[100];
int a[8];

int cnt(int v, int deep) {
    int res = 0;
    for (int i = deep; i > 0; i--) {
        res += v / w[i];
        v %= w[i];
    }
    return res;
}

int rec(int deep, int last) {
    int ms = 0;
    for (int j = 0; j < n; j++) ms += cnt(a[j], deep);

    if (ms < last) {
        int oms = ms;
        for (int i = 2; w[deep] * i <= max_v; i++) {
            w[deep + 1] = w[deep] * i;
            ms = min(ms, rec(deep + 1, oms));
        }
    }
    return ms;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_v = max(max_v, a[i]);
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }
    w[1] = 1;
    cout << rec(1, 2000000000ULL);
    return 0;
}