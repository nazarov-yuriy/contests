#include <iostream>

using namespace std;

int main() {
    long long int n;
    cin >> n;
    if (n == 4) {
        cout << "0 2" << endl;
    } else if (n == 5) {
        cout << "0 0" << endl;
    } else if (n == 6) {
        cout << "6 9" << endl;
    } else if (n % 2) {
        cout << n * (n - 3) / 2 << " 0" << endl;
    } else {
        cout << n * (n - 3) / 2 << ' ' << n * (n - 3) / 2 << endl;
    }
    return 0;
}