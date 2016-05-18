#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int maxt = 0, mint = 1000000000+9;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        mint = min(mint, t);
        maxt = max(maxt, t);
    }
    cout << maxt - mint;
    return 0;
}