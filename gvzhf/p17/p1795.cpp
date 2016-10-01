#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct husband {
    int id;
    int need;
    int approved;
};

int main() {
    int m, n;
    map<string, int> ids;
    int left[2002] = {};

    cin >> m;
    for (int i = 0; i < m; i++) {
        int cnt;
        string str;
        cin >> cnt >> str >> str;
        ids[str] = ids.size() + 1;
        left[ids[str]] = cnt;
    }

    vector<husband> hs;
    cin >> n;
    hs.resize(n);
    for (int i = 0; i < n; i++) {
        int cnt;
        string str;
        cin >> cnt >> str >> str;
        hs[n - 1 - i] = {ids[str], cnt, cnt};
    }

    int res = 0;
    while (hs.size()) {
        husband h = hs.back();
        if (left[h.id] == 0) {
            hs.pop_back();
        } else if (left[h.id] >= h.approved) {
            left[h.id] -= h.approved;
            hs.pop_back();
        } else {
            if (hs.size() > 1) {
                h.approved = left[h.id];
                hs[hs.size() - 1] = hs[hs.size() - 2];
                hs[hs.size() - 2] = h;
            } else {
                hs.pop_back();
            }
        }
        res++;
    }
    cout << res;
    return 0;
}