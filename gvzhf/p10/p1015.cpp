#include <iostream>
#include <set>
#include <map>

using namespace std;

// left
// right
// top
// front
// bottom
// rear
int rc(int c) {
    int le = (c & 0xf00000) >> 20, ri = (c & 0xf0000) >> 16, to = (c & 0xf000) >> 12, fr = (c & 0xf00) >> 8, bo = (c & 0xf0) >> 4, re = (c & 0xf) >> 0;
    return (fr << 20) | (re << 16) | (to << 12) | (ri << 8) | (bo << 4) | (le << 0);
}

int rcc(int c) {
    return rc(rc(rc(c)));
}

int rf(int c) {
    int le = (c & 0xf00000) >> 20, ri = (c & 0xf0000) >> 16, to = (c & 0xf000) >> 12, fr = (c & 0xf00) >> 8, bo = (c & 0xf0) >> 4, re = (c & 0xf) >> 0;
    return (le << 20) | (ri << 16) | (re << 12) | (to << 8) | (fr << 4) | (bo << 0);
}

int rb(int c) {
    return rf(rf(rf(c)));
}

int canon(int c) {
    int le = (c & 0xf00000) >> 20, ri = (c & 0xf0000) >> 16, to = (c & 0xf000) >> 12, fr = (c & 0xf00) >> 8, bo = (c & 0xf0) >> 4, re = (c & 0xf) >> 0;
    if (le != 1) {
        if (ri == 1) {
            c = rc(rc(c));
        } else {
            while ((c & 0xf) != 1) {
                c = rf(c);
            }
            c = rcc(c);
        }
    }
    ri = (c & 0xf0000) >> 16;
    if (ri == 2) {
        while ((c & 0xf) != 3) {
            c = rf(c);
        }
    } else {
        while ((c & 0xf) != 2) {
            c = rf(c);
        }
    }
    return c;
}

int main() {
    map<int, set<int>> mp;
    map<int, int> sort;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, sch = 0;
        for (int j = 0; j < 6; j++) {
            cin >> t;
            sch = (sch << 4) | t;
        }
        mp[canon(sch)].insert(i);
        sort[*mp[canon(sch)].begin()] = canon(sch);
    }
    cout << mp.size() << endl;
    for (auto it = sort.begin(); it != sort.end(); ++it) {
        for (auto jt = mp[it->second].begin(); jt != mp[it->second].end(); ++jt) {
            cout << *jt << ' ';
        }
        cout << endl;
    }
    return 0;
}