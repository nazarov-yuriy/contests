#include <iostream>

using namespace std;

int main() {
    long long int p;
    cin >> p;
    int res[p];
    for (long long int i = 0; i < p; i++) {
        res[i] = -1;
    }
    for (long long int i = 0; i < p; i++) {
        res[(i * i) % p] = (int) i;
    }
    for (long long int i = 0; i < p; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}