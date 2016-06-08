#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> nodes[n];
    int pointers[n];
    map<int, vector<pair<int, int>>> connections;
    vector<pair<int, int>> answ;
    for (int i = 0; i < n; i++) {
        nodes[i].insert(i);
        pointers[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        connections[c].push_back({min(a, b), max(a, b)});
    }
    int max = 0;
    int sets = n;
    for (auto it = connections.begin(); it != connections.end(); ++it) {
        max = it->first;
        for (auto jt = it->second.begin(); jt != it->second.end(); ++jt) {
            int f = pointers[jt->first], s = pointers[jt->second];
            if (f != s) {
                answ.push_back({jt->first, jt->second});
                sets--;
                for (auto kt = nodes[s].begin(); kt != nodes[s].end(); ++kt) pointers[*kt] = f;
                nodes[f].insert(nodes[s].begin(), nodes[s].end());
                if (sets == 1) {
                    goto out;
                }
            }
        }
    }
    out:
    cout << max << endl;
    cout << answ.size() << endl;
    for (auto it = answ.begin(); it != answ.end(); ++it) {
        cout << it->first+1 << ' ' << it->second+1 << endl;
    }
    return 0;
}