#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n = 5;
    int xo[n];
    int yo[n];
    long double a[n];
    long double da[n];
    for (int i = 0; i < n; i++) {
        cin >> xo[i] >> yo[i];
    }
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
            for (int l = 0; l < 5; l++) {
                for (int m = 0; m < 5; m++) {
                    for (int o = 0; o < 5; o++) {
                        if (o == j || o == k || o == l || o == m) continue;
                        if (j == k || j == l || j == m || k == l || k == m || l == m) continue;
                        int x[n] = {xo[o], xo[j], xo[k], xo[l], xo[m]};
                        int y[n] = {yo[o], yo[j], yo[k], yo[l], yo[m]};
                        for (int i = 0; i < n; i++) {
                            int dx = x[(i + 1) % n] - x[i];
                            int dy = y[(i + 1) % n] - y[i];
                            a[i] = atan2(dy, dx);
                            //cout << dx << ' ' << dy << ' ' << a[i] << endl;
                        }
                        //cout << endl;
                        for (int i = 0; i < n; i++) {
                            da[i] = fmod(a[(i + 1)] - a[i] + M_PI * 4.0, M_PI);
                            //cout << da[i] << endl;
                        }
                        if ((M_PI_2 < da[0] + da[1] && da[0] + da[1] < M_PI) &&
                            (M_PI_2 < da[1] + da[2] && da[1] + da[2] < M_PI) &&
                            (M_PI_2 < da[2] + da[3] && da[2] + da[3] < M_PI) &&
                            (M_PI_2 < da[3] + da[4] && da[3] + da[4] < M_PI) &&
                            (M_PI_2 < da[4] + da[0] && da[4] + da[0] < M_PI)) {
                            cout << "Yes";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "No";
    return 0;
}