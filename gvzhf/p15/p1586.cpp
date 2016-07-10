#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int v) {
    bool res = true;
    for (int i = 2; i < v; i++) {
        res &= 0 != v % i;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<uint64_t> starts[100];
    uint64_t res[2][100] = {};
    for (int i = 100; i <= 999; i++) {
        if (isPrime(i)) {
            starts[i / 10].push_back(i);
            res[0][i % 100]++;
        }
    }
    for (int i = 4; i <= n; i++) {
        for (int j = 0; j <= 99; j++) res[1 - i % 2][j] = 0;
        for (int j = 10; j <= 99; j++) {
            for (auto it = starts[j].begin(); it != starts[j].end(); ++it) {
                res[1 - i % 2][*it % 100] += res[i % 2][j];
                res[1 - i % 2][*it % 100] %= 1000000009;
            }
        }
    }
    uint64_t cnt = 0;
    for (int i = 0; i <= 99; i++) {
        cnt = (cnt + res[1 - n % 2][i]) % 1000000009;
    }
    cout << cnt;
    return 0;
}