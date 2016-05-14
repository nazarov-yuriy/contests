#include <iostream>

using namespace std;

int divisors(int v){
    int cnt = 0;
    for(int i = 1; i * i <= v; i++){
        if(v % i == 0) cnt++;
    }
    return cnt;
}

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    for(int l = k+1; l <= 10000; l++){
        if(divisors(l) == n && divisors(l-k) == m){
            cout << l;
            return 0;
        }
    }
    cout << 0;
    return 0;
}