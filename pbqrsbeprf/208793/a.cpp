#include <iostream>

using namespace std;

int main() {
    long long int n, res;
    cin >> n;
    res = n / 2;
    if (n % 2) res -= n;
    cout << res;
    return 0;
}