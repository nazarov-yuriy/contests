#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pers {
    int val;
    bool done;
};
int n, s;
vector<pers> val;

int find_pair(int from, int with) {
    for (int i = from; i < n; i++) {
        if (!val[i].done && val[i].val + with > s) return i;
    }
    return n;
}

bool gr(pers a, pers b) {
    return a.val < b.val;
}

int main() {
    cin >> n >> s;
    int res[n], pos = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        val.push_back({t, false});
    }
    sort(val.begin(), val.end(), gr);
    if (val.size() == 1) {
        cout << 1 << endl;
        cout << val[0].val;
        return 0;
    }
    if (val.size() == 2) {
        cout << (val[0].val + val[1].val > s ? 2 : 1) << endl;
        cout << val[0].val << ' ' << val[1].val;
        return 0;
    }
    if (val.size() == 3) {
        if (val[0].val + val[2].val > s) {
            cout << (val[2].val + val[1].val > s ? 3 : 2) << endl;
        } else {
            cout << 2 << endl;
        }
        cout << val[0].val << ' ' << val[2].val << ' ' << val[1].val;
        return 0;
    }
    int e = n - 1;
    int b = find_pair(0, val[e].val);
    while (b < e) {
        val[b].done = true;
        val[e].done = true;
        res[pos++] = val[b].val;
        res[pos++] = val[e--].val;
        b = find_pair(b, val[e].val);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!val[i].done) res[pos++] = val[i].val;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i < n - 1 && res[i] + res[i + 1] <= s) {
            cnt++;
            i++;
        } else {
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}
