#include <iostream>

using namespace std;

int main() {
    int r, l;
    cin >> r >> l;
    r--;
    for (int i = 2; i < 1000000; i++) {
        r -= r / i;
        l -= l / i;
    }
    cout << l - r;
    return 0;
}