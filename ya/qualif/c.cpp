#include <iostream>
#include <iomanip>

using namespace std;

int n;
double matrix[10][10];

long double prob(int cnt, int ignore) {
    if (cnt == 2) return 1;
    long double res = 0;
    for (int i = 0; i < n; i++) {
        if (ignore & (1 << i)) continue;
        long double p = 1;
        for (int j = 0; j < n; j++) if (i != j && !(ignore & (1 << j))) p *= matrix[i][j];
        res += p * prob(cnt - 1, ignore | (1 << i));
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << setprecision(15) << prob(n, 0);
    return 0;
}