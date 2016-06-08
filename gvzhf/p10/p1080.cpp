#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int colors[n] = {1};
    bool visited[n] = {};
    bool links[n][n] = {};
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        while (t) {
            t--;
            links[i][t] = links[t][i] = true;
            cin >> t;
        }
    }
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < n; i++) {
            if (colors[i] && !visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (links[i][j]) {
                        if (colors[j] && colors[j] == colors[i]) {
                            cout << -1;
                            return 0;
                        } else {
                            changed = true;
                            colors[j] = 3 - colors[i];
                        }
                    }
                }
                visited[i] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << colors[i]-1;
    }
    return 0;
}