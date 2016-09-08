
#include <iostream>

using namespace std;
#define N 100000

int main() {
    long long int n, res = 0, s;
    cin >> n;
    /*for (long long int u = N / 10; u < N; u++) {
        for (long long int l = 1; l < N; l++) {
            s = u * N + l;
            if ((0 == s % l) && (0 == s % u)) {
                res++;
            }
        }
    }
    cout << res << endl;*/
    if (n == 1) {
        cout << 14;
    } else if (n == 2) {
        cout << 155;
    } else {
        cout << 1575;
        for (int i = 3; i < n; i++) {
            cout << 0;
        }
    }
    return 0;
}