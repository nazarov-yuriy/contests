#include <iostream>

using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    int t1[n], t2[n], t3[n];
    bool done[n] = {};
    for (int i = 0; i < n; i++) {
        cin >> t1[i] >> t2[i] >> t3[i];
    }
    int t = 0, left = n;
    do {
        int start_left = left;
        do {
            int min_i = -1, min_t = 1000000;
            for (int i = 0; i < n; i++) {
                if (!done[i] && t1[i] <= t) {
                    if (t1[i] < min_t) {
                        min_i = i;
                        min_t = t1[i];
                    }
                }
            }
            if (min_i != -1) {
                t += t2[min_i];
                left--;
                done[min_i] = true;
                res = max(res, t - t3[min_i]);
            }
            if (start_left == left) t++;
        } while (start_left == left);
    } while (left);
    cout << res;
    return 0;
}