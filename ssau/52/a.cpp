#include <iostream>

using namespace std;

int main() {
    int n, m = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        m = max(m, t);
    }
    cout << m;
    return 0;
}