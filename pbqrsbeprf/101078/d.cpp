#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int res1 = (k+1)/2 - ((k - 1) / 3 + 1) / 2 + k/2 - (k/2)/2 + (k+1)/2 - (k/2+1)/2, res2 = 0;
        /*for (int j = 1; j <= k; j++) {
            if (j % 2) {
                if (3 * j + 1 > k) res2++;
                if (2 * j > k) res2++;
            } else {
                if (2 * j > k) res2++;
            }
        }
        cout << k << ' ' << res1 << ' ' << res2 << endl;*/
        cout << res1 << endl;
    }
    return 0;
}