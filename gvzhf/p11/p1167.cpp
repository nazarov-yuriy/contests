#include <iostream>
#include <list>

using namespace std;

struct p {
    int w;
    int b;
};

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    list <p> l;
    l.push_back({t == 0, t == 1});
    for (int i = 1; i < n; i++) {
        cin >> t;
        if (t ? l.back().b : l.back().w) {
            if (t)l.back().b++; else l.back().w++;
        } else {
            l.push_back({t == 0, t == 1});
        }
    }
    int m[k + 1][l.size() + 1] = {};
    int b[l.size() + 1] = {}, w[l.size() + 1] = {}, i = 0;
    for (auto it = l.begin(); it != l.end(); ++it) {
        b[i + 1] += it->b + b[i];
        w[i + 1] += it->w + w[i];
        m[1][i + 1] = b[i + 1] * w[i + 1];
        i++;
    }
    for (int stable = 2; stable <= k; stable++) {
        i = 0;
        for (auto it = l.begin(); it != l.end(); ++it) {
            m[stable][i + 1] = 500 * 500;
            for (int j = 0; j <= i; j++) {
                m[stable][i + 1] = min(m[stable][i + 1], (b[i + 1] - b[j]) * (w[i + 1] - w[j]) + m[stable - 1][j]);
            }
            i++;
        }
    }
    /*for (auto it = l.begin(); it != l.end(); ++it) {
        cout << it->b << ' ' << it->w << endl;
    }*/
    cout << m[k][l.size()];
    return 0;
}