#include <iostream>

using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    int l[n], r[n];
    int max_l = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        max_l = max(max_l, l[i]);
    }
    for (int i = 0; i < n; i++) {
        if (l[i] <= max_l && max_l <= r[i]) {
            res++;
        }
    }
    cout << res;
    return 0;
}