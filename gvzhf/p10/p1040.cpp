#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == b) return a;
    if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

int main() {
    int n, m;
    cin >> n >> m;
    bool adj[n][n];
    int num[n][n];
    bool visited[n];
    int f[m] = {};
    int t[m] = {};
    bool first = true;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            adj[i][j] = false;
            num[i][j] = 0;
        }
    }
    int counter = 1;
    int current = 0;
    for (int i = 0; i < m; i++) {
        cin >> f[i] >> t[i];
        f[i]--;
        t[i]--;
        adj[f[i]][t[i]] = adj[t[i]][f[i]] = true;
        if (first) {
            current = t[i];
            first = false;
            visited[f[i]] = true;
            visited[t[i]] = true;
            num[f[i]][t[i]] = num[t[i]][f[i]] = counter++;
        }
    }
    while (counter <= m) {
        bool step = true;
        while (step) {
            step = false;
            for (int i = 0; i < n; i++) {
                if (adj[current][i] && !num[current][i]) {
                    visited[i] = true;
                    num[i][current] = num[current][i] = counter++;
                    current = i;
                    step = true;
                }
            }
        }
        current = (current + 1) % n;
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << num[i][j] << ' ';
        }
        cout << endl;
    }*/
    cout << "YES" << endl;
    for (int i = 0; i < m; i++) {
        cout << num[f[i]][t[i]] << ' ';
    }
    return 0;
}