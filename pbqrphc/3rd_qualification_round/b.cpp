#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
        int l, swaps = 0;
        cin >> l;
        string f, s;
        cin >> f >> s;
        for (int i = 0; i < f.length() - 1; i++) {
            if (f[i] != s[i]) {
                f[i] = f[i] == '0' ? '1' : '0';
                f[i + 1] = f[i + 1] == '0' ? '1' : '0';
                swaps++;
            }
        }
        if (f == s) {
            cout << swaps << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}