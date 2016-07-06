#include <iostream>

using namespace std;

int main() {
    int a[10] = {};
    int n;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0; i < n; i++) {
        a[str[i] - '0'] = 1;
    }
    if (!a[1] && !a[2] && !a[3]) {
        cout << "NO";
        return 0;
    }
    if (!a[7] && !a[0] && !a[9]) {
        cout << "NO";
        return 0;
    }
    if (!a[1] && !a[4] && !a[7] && !a[0]) {
        cout << "NO";
        return 0;
    }
    if (!a[3] && !a[6] && !a[9] && !a[0]) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}