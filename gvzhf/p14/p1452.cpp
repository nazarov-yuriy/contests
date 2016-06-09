#include <iostream>
#include <set>
#include <map>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    map<int, int> num;
    unordered_set<int> unum;
    unordered_set<int> step3;
    map<int, int> checked;
    cin >> n;
    int max_num;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        max_num = max(max_num, t);
        num[t] = i + 1;
        unum.insert(t);
        checked[t] = 0;
    }
    if (num.size() == 1) {
        cout << 1 << endl << 1;
        return 0;
    }
    for (auto it = num.begin(); it != num.end(); ++it) {
        for (auto jt = it; ++jt != num.end();) {
            if (it->first + 3 * (jt->first - it->first) > max_num) break;
            if (unum.count(it->first + 3 * (jt->first - it->first)) && unum.count(it->first + 2 * (jt->first - it->first))) {
                step3.insert(jt->first - it->first);
            }
        }
    }
    if (step3.size() == 0) {
        for (auto it = num.begin(); it != num.end(); ++it) {
            for (auto jt = it; ++jt != num.end();) {
                if (unum.count(it->first + 2 * (jt->first - it->first))) {
                    cout << 3 << endl;
                    cout << num[it->first] << ' ' << num[jt->first] << ' ' << num[it->first + 2 * (jt->first - it->first)];
                    return 0;
                }
            }
        }
        cout << 2 << endl << num.begin()->second << ' ' << num.rbegin()->second;
        return 0;
    }
    int max_cnt = 0, max_step, max_from;
    for (auto it = step3.begin(); it != step3.end(); ++it) {
        for (auto jt = num.begin(); jt != num.end(); ++jt) {
            if (jt->first + *it * 3 > max_num) break;
            if (checked[jt->first] != *it) {
                int c = jt->first, cnt = 1;
                while (unum.count(c + *it)) {
                    c += *it;
                    cnt++;
                    checked[c] = *it;
                }
                if (cnt > max_cnt) {
                    max_cnt = cnt;
                    max_step = *it;
                    max_from = jt->first;
                }
                checked[jt->first] = *it;
            }
        }
    }
    cout << max_cnt << endl;
    for (int s = max_from, i = 0; i < max_cnt; i++, s += max_step) {
        cout << num[s] << ' ';
    }
    return 0;
}