#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, set<int>> inp;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        inp[t].insert(i);
    }
    int cnt = 0;
    set<int> added;
    for (auto it = inp.begin(); it != inp.end();) {
        auto cit = it;
        ++it;
        int next = (it == inp.end()) ? 1000000 : it->first;
        added.insert(cit->second.begin(), cit->second.end());
        if (cit->first <= added.size() && added.size() < next - 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    added.clear();
    for (auto it = inp.begin(); it != inp.end();) {
        auto cit = it;
        ++it;
        int next = (it == inp.end()) ? 1000000 : it->first;
        added.insert(cit->second.begin(), cit->second.end());
        if (cit->first <= added.size() && added.size() < next - 1) {
            cout << added.size();
            for (auto jt = added.begin(); jt != added.end(); ++jt) {
                cout << ' ' << *jt;
            }
            cout << endl;
        }
    }
    return 0;
}