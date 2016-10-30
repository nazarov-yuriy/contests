#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int res = 0;
    short unsigned m[str.length() + 1][str.length() + 1] = {};//[len][last]
    for (int i = 1; i <= str.length(); i++) {
        short unsigned id = 1;
        short unsigned map[130000] = {};
        for (int j = i; j <= str.length(); j++) {
            int pos = (str[j - 1] - 'a') * 5000 + m[i - 1][j - 1];
            if (map[pos]) {
                m[i][j] = map[pos];
            } else {
                m[i][j] = map[pos] = id++;
            }
        }
        res += id - 1;
    }
    cout << res;
    return 0;
}