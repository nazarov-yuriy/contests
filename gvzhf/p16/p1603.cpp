#include <iostream>

using namespace std;

char m[4][4];
bool vis[4][4];
string str;

bool find(int pos, int y, int x) {
    if (str[pos] != m[y][x]) return false;
    if (pos + 1 == str.length()) return true;
    vis[y][x] = true;
    bool res = false;
    if (!res && x < 3 && !vis[y][x + 1] && find(pos + 1, y, x + 1)) res = true;
    if (!res && x > 0 && !vis[y][x - 1] && find(pos + 1, y, x - 1)) res = true;
    if (!res && y < 3 && !vis[y + 1][x] && find(pos + 1, y + 1, x)) res = true;
    if (!res && y > 0 && !vis[y - 1][x] && find(pos + 1, y - 1, x)) res = true;
    vis[y][x] = false;
    return res;
}

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> str;
        for (int j = 0; j < 4; j++) m[i][j] = str[j];
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        bool ok = false;
        for (int y = 0; y < 4 && !ok; y++) {
            for (int x = 0; x < 4 && !ok; x++) {
                ok = find(0, y, x);
            }
        }
        cout << str << (ok ? ": YES" : ": NO") << endl;
    }
    return 0;
}