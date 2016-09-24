#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int links[n + 1] = {}, res[n + 1];
    int a[m], b[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        links[a[i]]++;
        links[b[i]]++;
    }
    int min_links = 1000000000, min_pos = 0;
    for (int i = 1; i <= n; i++) {
        res[i] = 1;
        if (links[i] < min_links) {
            min_links = links[i];
            min_pos = i;
        }
    }
    res[min_pos] = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] == min_pos) res[b[i]] = 0;
        if (b[i] == min_pos) res[a[i]] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}