#include <iostream>

using namespace std;

int main() {
    string str;
    int n;
    cin >> n >> str;
    int cnt[256] = {};
    for (unsigned i = 0; i < str.length(); ++i) {
        cnt[str[i]]++;
        if (cnt[str[i]] > 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}