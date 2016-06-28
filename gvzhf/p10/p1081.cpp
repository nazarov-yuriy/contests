#include <iostream>

using namespace std;

long long int co[100] = {1}, cz[100] = {1};

long long int zero(int n);

long long int one(int n) {
    if (co[n]) return co[n];
    return (co[n] = zero(n - 1));
}

long long int zero(int n) {
    if (cz[n]) return cz[n];
    return (cz[n] = zero(n - 1) + one(n - 1));
}

int main() {
    long long int n, k, res = 0;
    cin >> n >> k;
    k--;
    for (int i = n - 1; i >= 0; i--) {
        if (!(res & (1ULL << (i + 1)))) {
            if (zero(i) <= k) {
                res |= (1ULL << i);
                k -= zero(i);
            }
        }
    }
    if (k) {
        cout << -1 << endl;
    } else {
        for (int i = n - 1; i >= 0; i--) {
            cout << (res & (1ULL << i) ? 1 : 0);
        }
    }
    return 0;
}