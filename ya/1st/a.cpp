#include <iostream>

using namespace std;

int main() {
    int p, a, b;
    cin >> p >> a >> b;
    if (b > p) {
        cout << -1;
        return 0;
    }
    cout << max(p, a + b);
    return 0;
}