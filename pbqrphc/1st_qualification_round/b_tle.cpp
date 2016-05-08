#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, h;
        cin >> n >> h;
        int l[n + 1] = {};
        int on[n + 1] = {};
        int sum_len = 0;
        for (int j = 0; j < n; j++) {
            cin >> l[j];
            sum_len += l[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> on[j];
        }
        int run = 0;
        int cnt = 0;
        bool seen = false;
        for (int j = 0; j < n; j++) {
            if (on[j]) {
                run = 0;
                seen = true;
            } else {
                if (run + l[j] > h - 1 || (!seen && sum_len < h) ) {
                    run = 0;
                    seen = true;
                    cnt++;
                } else {
                    run += l[j];
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}