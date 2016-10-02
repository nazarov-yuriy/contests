#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    srand(2063);
    int m;
    cin >> m;
    for (int i = 2; i <= m + 1; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = j + 1; k <= i; k++) {
                cout << "? " << j << " " << k << endl;
            }
        }
        int r = rand() % (i - 1);
        cout << "! " << r + 1 << " " << r + 2 << endl;
    }
    return 0;
}