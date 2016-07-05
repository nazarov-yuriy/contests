#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    int p[n + 1];
    set<int> sets[n + 1];
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sets[i].insert(i);
    }
    for (int i = 0; i < k; i++) {
        int f, t;
        cin >> f >> t;
        if (!sets[p[f]].count(t)) {
            int pt = p[t];
            for (auto it = sets[pt].begin(); it != sets[pt].end(); ++it) {
                p[*it] = p[f];
                sets[p[f]].insert(*it);
            }
            sets[pt].clear();
        }
    }
    /*for (int i = 0; i < m; i++) {
        int f, t;
        cin >> f >> t;
    }*/
    set<int> uniq;
    for (int i = 1; i <= n; i++) {
        uniq.insert(p[i]);
    }
    cout << uniq.size() - 1;
    return 0;
}