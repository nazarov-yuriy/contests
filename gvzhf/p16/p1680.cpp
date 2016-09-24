#include <iostream>
#include <set>

using namespace std;

int main() {
    int y, n, q;
    set<string> passed;
    cin >> y >> n >> q;
    string str, trimmed;
    getline(cin, str);
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        if ('0' <= str[str.length() - 1] && str[str.length() - 1] <= '9' && str[str.length() - 2] == '#') {
            trimmed = str.substr(0, str.length() - 3);
        } else {
            trimmed = str;
        }
        if (!passed.count(trimmed) && passed.size() == q) {
            cout << str;
            return 0;
        } else {
            passed.insert(trimmed);
        }
    }
    return 0;
}