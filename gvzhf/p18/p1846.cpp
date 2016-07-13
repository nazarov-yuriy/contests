#include <iostream>
#include <map>

using namespace std;
#define N 330
int buckets[N][N] = {};
int gcds[N] = {};

int gcd(int a, int b) {
    if (0 == b)
        return a;
    else
        return gcd(b, a % b);
}

int add(int v, int pos) {
    int c;
    buckets[c = pos / N][pos % N] = v;
    int bucket_gcd = 0, res = 0;
    for (int i = 0; i < N; i++) {
        if (buckets[c][i]) {
            if (bucket_gcd)
                bucket_gcd = gcd(bucket_gcd, buckets[c][i]);
            else
                bucket_gcd = buckets[c][i];
        }
    }
    gcds[c] = bucket_gcd;
    for (int i = 0; i < N; i++) {
        if (gcds[i]) {
            if (res)
                res = gcd(res, gcds[i]);
            else
                res = gcds[i];
        }
    }
    return max(1, res);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, pos = 0;
    cin >> n;
    map<int, int> numbers_count;
    map<int, int> numbers_pos;
    int last = 0;
    for (int i = 0; i < n; i++) {
        char c;
        int t;
        cin >> c >> t;
        if ('+' == c) {
            if (numbers_count[t]) {
                numbers_count[t]++;
                cout << last << endl;
            } else {
                numbers_pos[t] = pos++;
                numbers_count[t]++;
                cout << (last = add(t, numbers_pos[t])) << endl;
            }
        } else {
            if (numbers_count[t] > 1) {
                numbers_count[t]--;
                cout << last << endl;
            } else {
                numbers_count[t]--;
                cout << (last = add(0, numbers_pos[t])) << endl;
                numbers_pos.erase(t);
            }
        }
    }
    return 0;
}