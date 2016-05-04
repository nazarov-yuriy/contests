#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;
    if (k % 2 == 0 && k % 4 != 0) k = k / 2;
    for (int i = 2; i < 20009; i++) {
        if (k % (i + 1) == 0) {
            cout << i;
            return 0;
        }
    }
    cout << k - 1;
    return 0;
}