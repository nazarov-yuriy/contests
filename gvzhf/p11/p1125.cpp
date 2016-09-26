#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int m, n;
    string map[50];
    unordered_set<int> squares;
    for (int i = 0; i < 100; i++) {
        squares.insert(i * i);
    }
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> map[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            if (t % 2) {
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < n; l++) {
                        int distance = (k - i) * (k - i) + (l - j) * (l - j);
                        if (squares.count(distance)) {
                            map[k][l] = (map[k][l] == 'B') ? 'W' : 'B';
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cout << map[i] << endl;
    }
    return 0;
}