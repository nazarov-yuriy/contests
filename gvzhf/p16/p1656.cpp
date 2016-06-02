#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int h[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> h[i][j];
        }
    }
    int run = 1;
    while (run) {
        run = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (h[i][j] > h[i][j + 1]) {
                    swap(h[i][j], h[i][j + 1]);
                    run++;
                }
                if (h[i][n - 1 - j] > h[i][n - 1 - j - 1]) {
                    swap(h[i][n - 1 - j], h[i][n - 1 - j - 1]);
                    run++;
                }
                if (h[j][i] > h[j + 1][i]) {
                    swap(h[j][i], h[j + 1][i]);
                    run++;
                }
                if (h[n - 1 - j][i] > h[n - 1 - j - 1][i]) {
                    swap(h[n - 1 - j][i], h[n - 1 - j - 1][i]);
                    run++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << h[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}