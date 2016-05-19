#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    char map[n + 2][n + 2];
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            map[i][j] = '#';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            while ('#' > (c = getchar())) { }
            map[i + 1][j + 1] = c;
        }
    }
    map[1][0] = '.';
    map[0][1] = '.';
    map[1][1] = 'o';
    map[n + 1][n] = '.';
    map[n][n + 1] = '.';
    map[n][n] = 'o';
    bool keep_run = true;
    while (keep_run) {
        keep_run = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i + 1][j + 1] == '.' && (map[i + 1][j] == 'o' || map[i][j + 1] == 'o' || map[i + 1][j + 2] == 'o' || map[i + 2][j + 1] == 'o')) {
                    map[i + 1][j + 1] = 'o';
                    keep_run = true;
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (map[i][j] == 'o') {
                if (map[i - 1][j] == '#') res++;
                if (map[i + 1][j] == '#') res++;
                if (map[i][j - 1] == '#') res++;
                if (map[i][j + 1] == '#') res++;
            }
        }
    }
    cout << res * 9;
    return 0;
}