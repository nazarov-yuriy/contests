#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    string str;
    cin >> n >> m;
    short int prev[2][3002] = {{},
                               {}};
    getline(cin, str);
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        for (int j = 1; j <= m; j++) {
            prev[i % 2][j] = str[j * 2 - 2] == '1';
            int t = (prev[0][j - 1] << 3) | (prev[0][j] << 2) | (prev[1][j - 1] << 1) | (prev[1][j] << 0);
            if (t == 0b0111 || t == 0b1011 || t == 0b1101 || t == 0b1110) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}