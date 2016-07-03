#include <iostream>

using namespace std;

int main() {
    long long int n, prev, curr, max_up = -5000000000LL, max_l = 1, max_r = 2;
    ios_base::sync_with_stdio(0);
    cin >> n >> prev;
    for (int i = 1; i < n; i++) {
        cin >> curr;
        if (abs(curr - prev) > max_up) {
            max_up = abs(curr - prev);
            max_l = i;
            max_r = i + 1;
        }
        prev = curr;
    }
    cout << max_l << ' ' << max_r;
    return 0;
}