#include <iostream>

using namespace std;

unsigned long long int cache[25][25];

unsigned long long int f(int n, int a) {
    if (n == 1) return 1;
    if (cache[n][a] != 0) return cache[n][a];
    long long int res = 0;
    for (int i = 0; i <= a; i++) {
        res += f(n - 1, i);
    }
    return (cache[n][a] = res);
}

int main() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            cache[i][j] = 0;
        }
    }
    int n, a, b;
    cin >> n >> a >> b;
    cout << f(n + 1, a) * f(n+1, b) << endl;
    //cout << f(n + 1, a) << endl;
    //cout << f(n + 1, b) << endl;
    return 0;
}