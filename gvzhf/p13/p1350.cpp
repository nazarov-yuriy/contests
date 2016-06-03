#include <iostream>
#include <map>
#include <vector>

using namespace std;

enum st {
    absent,
    maybe_present
};

int main() {
    map<string, st> mp;
    string str;
    int n, k, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        mp[str] = maybe_present;
    }
    cin >> k;
    int ni0;
    cin >> ni0;
    for (int j = 0; j < ni0; j++) {
        cin >> str;
        mp[str] = absent;
    }
    int cnt_abs = 0, cnt_maybe = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second == maybe_present)
            cnt_maybe++;
        else
            cnt_abs++;
    }
    vector<string> inp[k];
    for (int i = 0; i < k; i++) {
        int ni;
        cin >> ni;
        for (int j = 0; j < ni; j++) {
            cin >> str;
            inp[i].push_back(str);
        }
    }
    cin >> m;
    for (int i = 0; i < k; i++) {
        int my_abs = 0, my_maybe = 0;
        for (int j = 0; j < inp[i].size(); j++) {
            if (mp[inp[i][j]] == maybe_present) {
                my_maybe++;
            } else {
                my_abs++;
            }
        }
        if (my_maybe == 0) {
            cout << "YES" << endl;
        } else if (m + my_maybe > cnt_maybe) {
            cout << "NO" << endl;
        } else {
            cout << "MAYBE" << endl;
        }
    }
    return 0;
}