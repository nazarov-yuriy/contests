#include <iostream>
#include <vector>

using namespace std;

int get_max(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    cout << "? " << a << ' ' << b << endl;
    string str;
    cin >> str;
    if (">" == str) {
        return a;
    }
    if ("<" == str) {
        return b;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    int m[12][n + 1];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j <= n; j++) {
            m[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        m[0][i] = i + 1;
    }
    int tn = n, cur = 1;
    while (tn > 1) {
        int pn = tn;
        tn = tn / 2;
        for (int i = 0; i < tn; i++) {
            m[cur][i] = get_max(m[cur - 1][2 * i], m[cur - 1][2 * i + 1]);
        }
        if (pn % 2 && pn != 1) {
            tn++;
            m[cur][tn - 1] = m[cur - 1][(tn - 1) * 2];
        }
        cur++;
    }
    int max_p = m[cur - 1][0];
    //cout << m[cur - 1][0];
    tn = n;
    vector<int> merges;
    for (int l = 0; l < 12; l++) {
        for (int i = 0; i < n; i++) {
            if (m[l][i] == max_p) {
                if (i % 2) {
                    merges.push_back(m[l][i - 1]);
                } else {
                    if (m[l][i + 1]) merges.push_back(m[l][i + 1]);
                }
            }
        }
    }
    if (merges.size() == 1) {
        cout << "! " << merges[0] << endl;
    } else {
        auto it = merges.begin();
        int res = merges[0];
        ++it;
        for (; it != merges.end(); ++it) {
            res = get_max(res, *it);
        }
        cout << "! " << res << endl;
    }
    return 0;
}