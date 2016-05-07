#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n < 1){
        cout << 0;
        return 0;
    }
    int v[n + 1] = {};
    int from[n] = {};
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        v[i] = t;
        for (int j = 0; j < n; j++) {
            if ((from[j] && from[j] != i) || j == 0) {
                if (!from[(j + t) % n]) from[(j + t) % n] = i;
                if (0 == (j + t) % n) break;
            }
        }
    }
    int count = 0;
    int rem = 0;
    do{
        count++;
        rem = (rem + 15000*n - v[from[rem]]) % n;
    } while(rem);
    cout << count << endl;
    do{
        cout << v[from[rem]] << ' ';
        rem = (rem + 15000*n - v[from[rem]]) % n;
    } while(rem);
    return 0;
}
