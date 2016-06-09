#include <iostream>
#include <map>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    map<int, int> inp;
    for (int i = 0; i < n; i++) {
        unsigned int t;
        cin >> t;
        inp[t] = i + 1;
    }
    n = inp.size();
    if (n == 1) {
        cout << 1 << endl << 1;
        return 0;
    } else if (n == 2) {
        cout << 2 << endl << inp.begin()->second << ' ' << inp.rbegin()->second;
        return 0;
    }
    short int L[n][n] = {};
    int set[n];
    short int max_cnt = 2;
    auto it = inp.begin();
    for (int i = 0; i < n; ++it, i++) {
        set[i] = it->first;
        L[i][n - 1] = 2;
    }
    int max_from = set[0], max_step = set[1] - set[0];
    for (int j = n - 2; j >= 1; j--) {
        int i = j - 1, k = j + 1;
        while (i >= 0 && k <= n - 1) {
            if (set[i] + set[k] < 2 * set[j]) {
                k++;
            } else if (set[i] + set[k] > 2 * set[j]) {
                L[i][j] = 2, i--;
            } else {
                L[i][j] = L[j][k] + 1;
                if (max_cnt < L[i][j]) {
                    max_cnt = L[i][j];
                    max_from = set[i];
                    max_step = set[j] - set[i];
                }
                i--;
                k++;
            }
        }
        while (i >= 0) {
            L[i][j] = 2;
            i--;
        }
    }
    cout << max_cnt << endl;
    for (int s = max_from, i = 0; i < max_cnt; i++, s += max_step) {
        cout << inp[s] << ' ';
    }
    return 0;
}