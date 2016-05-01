#include <iostream>

using namespace std;

int main() {
    const int N = 3200; //sqrt(10'000'000)
    int *erato = new int[N];
    int *counts = new int[N * N]();
    for (int i = 1; i < N; i++) {
        erato[i] = 1;
    }
    for (long long int i = 2; i < N; i++) {
        if (erato[i]) {
            for (long long int j = i * i; j < N; j += i) {
                erato[j] = 0;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for (int j = 1; j < N; j++) {
            if (0 == t % j) {
                counts[j]++;
                if (t/j >= N) counts[t / j]++;
            }
        }
    }
    int max_counts = 0;
    for (int j = 2; j < N * N; j++) {
        max_counts = max(max_counts, counts[j]);
    }
    if (max_counts == 0) {
        cout << "0";
    } else if (max_counts == 1) {
        cout << "1";
    } else if (max_counts == 2) {
        cout << "2";
    } else {
        cout << "infinity";
    }
    return 0;
}