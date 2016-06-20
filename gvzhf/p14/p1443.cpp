#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long int s, l, n;
    long double sd, ld;
    cin >> n >> sd >> ld;
    s = lround(sd * 10000);
    l = lround(ld * 10000);
    long long int r = s % l;
    if(r == 0){
        cout << n * (s / l);
    }else{
        long long int t = l / r;
        cout << n * (s / l) + ((n + t - 1) / t);
    }
    return 0;
}