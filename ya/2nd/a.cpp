#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int cost[256] = {};
    string target;
    cin >> target;
    for (int i = 0; i < m; i++) {
        int c, l;
        string w;
        cin >> l >> c >> w;
        for (int j = 0; j < l; j++) {
            cost[w[j] - 'a'] = cost[w[j] - 'a'] ? min(c, cost[w[j] - 'a']) : c;
        }
    }
    long int summ = 0;
    for (int i = 0; i < n; i++) {
        if (cost[target[i] - 'a'] == 0) {
            cout << -1;
            return 0;
        } else {
            summ += cost[target[i] - 'a'];
        }
    }
    cout << summ;
    return 0;
}