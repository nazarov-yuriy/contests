#include <iostream>

using namespace std;

int main() {
    long long int n, h, k, added = 0, seconds = 0;
    cin >> n >> h >> k;
    for (int i = 0; i < n; i++) {
        long long int t;
        cin >> t;
        if (h + k < t + added) {
            long long int cnt = (t + added - h) / k;
            added -= cnt * k;
            seconds += cnt;
        }
        while (h < t + added) {
            seconds++;
            added = max(0LL, added - k);
        }
        added += t;
    }
    seconds += (added + k - 1) / k;
    cout << seconds;
    return 0;
}