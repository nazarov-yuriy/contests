#include <iostream>

using namespace std;

int main() {
    int l, n;
    cin >> l >> n;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        l = k * (l / k);
    }
    cout << (l > 0 ? "NO" : "YES");
    return 0;
}