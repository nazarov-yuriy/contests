#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n / 2 << endl;
    while (n) {
        int dec = n == 3 ? 3 : 2;
        cout << dec << ' ';
        n -= dec;
    }
    return 0;
}