#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char teddy_hater[n] = {};
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        teddy_hater[--t] = 1;
    }
    long long int time = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((teddy_hater[0] || teddy_hater[i] || teddy_hater[j]) && m - teddy_hater[0] - teddy_hater[i] - teddy_hater[j] >= n / 3 - 1) {
                time++;
            }
        }
    }
    cout << time;
    return 0;
}