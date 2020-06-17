#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int min_ak = INT32_MAX;
        int max_ak = INT32_MIN;
        int prev = INT32_MIN;
        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            if (t < prev) {
                cout << "NO";
                return 0;
            }
            prev = t;
            min_ak = min(min_ak, t);
            max_ak = max(max_ak, t);
        }
        a[i].first = min_ak;
        a[i].second = max_ak;
    }
    sort(a.begin(), a.end());
    pair<int, int> prev = {0, 0};
    for (int i = 0; i < n; i++) {
        if (a[i].first < prev.second) {
            cout << "NO";
            return 0;
        }
        prev = a[i];
    }
    cout << "YES";
    return 0;
}