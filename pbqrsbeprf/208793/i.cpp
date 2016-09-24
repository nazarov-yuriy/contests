#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> srt, res;
    long long int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t = 0;
        cin >> t;
        srt.insert(t);
    }
    for (int i = 1; i < 200000; i++) {
        if (i > m) break;
        if (!srt.count(i)) {
            m -= i;
            res.insert(i);
        }
    }
    cout << res.size() << endl;
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << ' ';
    }
    return 0;
}