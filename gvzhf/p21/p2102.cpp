#include <iostream>

using namespace std;

int main() {
    int res = 0;
    long long unsigned int n;
    cin >> n;
    while (n > 1) {
        lbl:
        for (long long unsigned i = 2; i * i <= n; i++) {
            if (0 == (n % i)) {
                n /= i;
                res++;
                goto lbl;
            }
            if (i > 3000000) {
                cout << (res == 19 ? "Yes" : "No");
                return 0;
            }
        }
        n /= n;
        res++;
    }
    cout << (res == 20 ? "Yes" : "No");
    return 0;
}