#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int vals[n];
    map<int, vector<int>> by_val;
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
        by_val[vals[i]].push_back(i);
    }
    /*for (auto it = by_val.begin(); it != by_val.end(); ++it) {
        cout << it->first << ": ";
        for (auto jt = it->second.begin(); jt != it->second.end(); ++jt) {
            cout << *jt << ' ';
        }
        cout << endl;
    }*/
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        if (by_val.count(x) > 0) {
            auto low = lower_bound(by_val[x].begin(), by_val[x].end(), l);
            if(low == by_val[x].end() || *low > r){
                cout << '0';
            }else{
                cout << '1';
            }
        } else {
            cout << '0';
        }
    }
    return 0;
}