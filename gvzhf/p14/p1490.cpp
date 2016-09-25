#include <iostream>

using namespace std;

int main() {
    long long int r, x, y, res = 0;
    cin >> r;
    x = r;
    for (y = 0; y < r; y++) {
        while (x * x + y * y >= r * r) {
            x--;
        }
        if (x * x + y * y < r * r) {
            x++;
        }
        res += x;
    }
    cout << res * 4ll;
    return 0;
}