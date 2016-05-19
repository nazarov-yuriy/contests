#include <iostream>

using namespace std;

int main() {
    double pd, qd;
    cin >> pd >> qd;
    long long int p = pd * 100.0000001, q = qd * 100.0000001;
    for (long int i = 1; i < 1000000000; i++) {
        long long int c = i * q / 10000;
        if (c * 10000 >= i * q) c--;
        if (c * 10000 > i * p) {
            cout << i;
            return 0;
        }
    }
    return 0;
}