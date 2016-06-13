#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int min_l = 2000000000, max_r = -2000000000;
    for (int i = 0; i < n; i++) {
        int x;
        string direction;
        cin >> x >> direction;
        if (direction == "+")
            max_r = max(max_r, x);
        else
            min_l = min(min_l, x);
    }
    if (max_r > min_l) {
        cout << 2;
    } else {
        cout << 1;
    }
    return 0;
}