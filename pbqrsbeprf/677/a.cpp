#include <iostream>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    int res = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        res += ((t > h) ? 2 : 1 );
    }
    cout << res;
    return 0;
}