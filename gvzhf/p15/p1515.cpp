#include <iostream>

using namespace std;

int main() {
    long long int n, sum = 0, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t > sum + 1) {
            cout << sum + 1;
            return 0;
        }
        sum += t;
    }
    cout << sum + 1;
    return 0;
}