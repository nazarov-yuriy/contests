#include <iostream>

using namespace std;

typedef long long int u64;

u64 addmod(u64 x, u64 y, u64 m) {
    x %= m;
    y %= m;
    u64 sum = x - m + y;
    return sum < 0 ? sum + m : sum;
}

u64 timesmod(u64 x, u64 y, u64 m) {
    x %= m;
    y %= m;
    u64 a = x < y ? x : y;
    u64 b = x < y ? y : x;
    u64 product = 0;
    for (; a != 0; a >>= 1, b = addmod(b, b, m))
        if (a & 1) product = addmod(product, b, m);
    return product;
}

int main() {
    u64 n, k, m, t;
    cin >> n >> k >> m;
    pair<u64, u64> pairs[200];
    pairs[0] = {1, 0};
    pairs[1] = {0, 1};
    pairs[2] = {(k - 1) % m, (k - 1) % m};
    pairs[3] = {timesmod((k - 1), (k - 1), m), timesmod((k - 1), k, m)};
    for (int i = 2; i < 80; i++) {
        pairs[2 * i].first = (timesmod(pairs[2 * i - 2].first, pairs[2 * i - 2].first, m) + timesmod(pairs[2 * i - 2].second, pairs[2 * i - 1].first, m)) % m;
        pairs[2 * i].second = (timesmod(pairs[2 * i - 2].first, pairs[2 * i - 2].second, m) + timesmod(pairs[2 * i - 2].second, pairs[2 * i - 1].second, m)) % m;

        pairs[2 * i + 1].first = (timesmod(pairs[2 * i - 1].first, pairs[2 * i - 2].first, m) + timesmod(pairs[2 * i - 1].second, pairs[2 * i - 1].first, m)) % m;
        pairs[2 * i + 1].second = (timesmod(pairs[2 * i - 1].first, pairs[2 * i - 2].second, m) + timesmod(pairs[2 * i - 1].second, pairs[2 * i - 1].second, m)) % m;
    }
    pair<u64, u64> res[2];
    res[0] = {1, 0};
    res[1] = {0, 1};
    u64 odd = n & 1;
    n >>= 1;
    for (int i = 0; i < 63; i++) {
        if (n & (1ULL << i)) {
            u64 f0, f1, s0, s1;
            f0 = (timesmod(pairs[2 * i + 2].first, res[0].first, m) + timesmod(pairs[2 * i + 2].second, res[1].first, m)) % m;
            s0 = (timesmod(pairs[2 * i + 2].first, res[0].second, m) + timesmod(pairs[2 * i + 2].second, res[1].second, m)) % m;
            f1 = (timesmod(pairs[2 * i + 3].first, res[0].first, m) + timesmod(pairs[2 * i + 3].second, res[1].first, m)) % m;
            s1 = (timesmod(pairs[2 * i + 3].first, res[0].second, m) + timesmod(pairs[2 * i + 3].second, res[1].second, m)) % m;
            res[0].first = f0;
            res[0].second = s0;
            res[1].first = f1;
            res[1].second = s1;
        }
    }
    if (odd) {
        t = (res[1].first + timesmod(res[1].second, (k - 1), m)) % m;
    } else {
        t = (res[0].first + timesmod(res[0].second, (k - 1), m)) % m;
    }
    cout << t << endl;
    return 0;
}