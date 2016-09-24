#include <iostream>

using namespace std;

int main() {
    int n, min_p = 200, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, p;
        cin >> a >> p;
        min_p = min(min_p, p);
        res += min_p * a;
    }
    cout << res;
    return 0;
}