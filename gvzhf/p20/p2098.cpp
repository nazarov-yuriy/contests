#include <iostream>

using namespace std;

int main() {
    long long int b, c, d, k, p, cash = 0, ins = 0;
    cin >> b;
    cin >> c >> d;
    cin >> k >> p;

    for (int i = 1; i <= k; i++) {
        cash += (c + d * i) * 100;
        ins += (c + d * i) * (100 + p);
    }
    if (cash + b * 100 < ins) {
        cout << "Cash" << endl;
        cout << (ins - cash - b * 100) / 100 << '.';
        if ((ins - cash - b * 100) % 100 < 10) cout << '0';
        cout << (ins - cash - b * 100) % 100;
    } else {
        cout << "Insurance" << endl;
        cout << (cash + b * 100 - ins) / 100 << '.';
        if ((cash + b * 100 - ins) % 100 < 10) cout << '0';
        cout << (cash + b * 100 - ins) % 100;
    }
    return 0;
}