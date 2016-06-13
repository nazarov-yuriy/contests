#include <iostream>

using namespace std;

long long int cache[1000001] = {1};

static long long int pow2(long long int p) {
    if (p < 1) return 1;
    if (cache[p]) return cache[p];
    return (cache[p] = 2 * pow2(p - 1) % 1000000007);
}

int main() {
    long long int n, k, res = 1;
    cin >> n >> k;
    for (long long int i = 1; i <= k; i++) {
        res += (pow2(i - 2) * (n + 1 - i)) % 1000000007;
    }
    cout << res % 1000000007;
    return 0;
}