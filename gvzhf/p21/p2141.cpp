#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int sum[n + 1];
    long long int s = 0;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        long long int t;
        cin >> t;
        if (i % 2) {
            s += t;
        } else {
            s -= t;
        }
        sum[i] = s;
    }

    long long int max_sum[n + 2];
    long long int min_sum[n + 2];
    min_sum[0] = min_sum[1] = 0;
    for (int i = 2; i <= n; i += 2) {
        min_sum[i] = min_sum[i + 1] = min(min_sum[i - 2], sum[i]);
    }
    max_sum[1] = max_sum[2] = sum[1];
    for (int i = 3; i <= n; i += 2) {
        max_sum[i] = max_sum[i + 1] = max(max_sum[i - 2], sum[i]);
    }
//    for (int i = 0; i <= n; i++) {
//        cout << sum[i] << endl;
//    }

    long long int answ = 0;
    for (int j = 1; j <= n; j++) {
        answ = max(answ, sum[j] - min_sum[j]);
        answ = max(answ, -sum[j] + max_sum[j]);
    }
    cout << answ;
    return 0;
}