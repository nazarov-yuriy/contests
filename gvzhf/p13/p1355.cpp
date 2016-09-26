#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b;
        if (0 == b % a) {
            int res = 1;
            c = b / a;
            for (int i = 2; i < 33000; i++) {
                while (0 == c % i) {
                    c /= i;
                    res++;
                }
            }
            if (c > 1) res++;
            cout << res << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}