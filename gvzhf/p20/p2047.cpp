#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> primes(0);
int *erato;
int *cache;

int divisors(int val) {
    int orig = val;
    if (cache[val]) return cache[val];
    if (erato[val]) return 2;
    for (auto it = primes.begin(); it != primes.end(); ++it) {
        int power = 0;
        while (0 == val % *it) {
            power++;
            val /= *it;
        }
        if (power) return cache[orig] = (1 + power) * divisors(val);
    }
}

int main() {
    const int N = 1600000;
    erato = new int[N]();
    cache = new int[N]();
    cache[1] = 1;
    for (int i = 2; i < N; i++) {
        erato[i] = 1;
    }
    for (long long int i = 2; i < N; i++) {
        if (erato[i]) {
            for (long long int j = i * i; j < N; j += i) {
                erato[j] = 0;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (erato[i]) primes.push_back(i);
    }

    int *viable = new int[N]();
    int iter = 0;
    int pma = N - 200;
    while (1) {
        int size = 0, ma = 0;
        for (int h = max(2, pma - 50); h < pma && size < 1; h++) {
            for (int i = 2; i <= 50; i++) {
                if (viable[h + i] >= iter && i == divisors(h + i)) {
                    viable[h] = viable[h + i] + 1;
                    size++;
                    ma = max(ma, h);
                    break;
                }
            }
        }
        for (int h = max(2, pma - 200); h < N - 200 && size < 1; h++) {
            for (int i = 2; i <= 200; i++) {
                if (viable[h + i] >= iter && i == divisors(h + i)) {
                    viable[h] = viable[h + i] + 1;
                    size++;
                    ma = max(ma, h);
                    break;
                }
            }
        }
        pma = ma;
        iter++;
        if (size == 0) break;
    }
    int n = 3;
    cin >> n;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = last; j < N; j++) {
            if (viable[j] == iter - i){
                cout << j - last << ' ';
                last = j;
                break;
            }
        }
    }
    return 0;
}