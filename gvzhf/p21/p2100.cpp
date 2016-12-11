#include <iostream>

using namespace std;

int main() {
    int n, res = 2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        res++;
        if (str.length() > 4 && str.substr(str.length() - 4, 4) == "+one")
            res++;
    }
    if (res == 13) res++;
    cout << 100 * res;
}