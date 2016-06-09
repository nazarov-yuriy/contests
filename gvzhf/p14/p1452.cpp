#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    map<int, int> inp;

    for (int i = 0; i < n; i++) {
        int t;
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
    short int d[n][n] = {};
    int set[n];
    unordered_map<int, int> pos;
    {
        int i = 0;
        for (auto it = inp.begin(); it != inp.end(); ++it, i++) {
            set[i] = it->first;
            pos[it->first] = i;
            d[i][n - 1] = d[n - 1][i] = 2;
        }
    }
    int max_cnt = 0, max_from = 0, max_step = 0;
    bool need_recalc = true;
    while (need_recalc) {
        need_recalc = false;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 2; j > i; j--) {
                int k = 2 * set[j] - set[i];
                if (pos.count(k)) {
                    if (d[j][pos[k]]) {
                        d[i][j] = d[j][pos[k]] + 1;
                        if (d[i][j] > max_cnt) {
                            max_cnt = d[i][j];
                            max_from = set[i];
                            max_step = set[j] - set[i];
                        }
                    } else {
                        need_recalc = true;
                    }
                } else {
                    d[i][j] = 2;
                }
            }
        }
    }
    cout << max_cnt << endl;
    for (int s = max_from, i = 0; i < max_cnt; i++, s += max_step) {
        cout << inp[s] << ' ';
    }
    return 0;
}