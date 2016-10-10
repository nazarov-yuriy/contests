#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    double res = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool nearest = true;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    int dx1 = x[k] - x[i];
                    int dx2 = x[k] - x[j];
                    int dy1 = y[k] - y[i];
                    int dy2 = y[k] - y[j];
                    if (dx1 * dy2 == dx2 * dy1) {
                        if (dx1) {
                            if ((x[i] < x[k] && x[k] < x[j]) || (x[j] < x[k] && x[k] < x[i])) nearest = false;
                        } else {
                            if ((y[i] < y[k] && y[k] < y[j]) || (y[j] < y[k] && y[k] < y[i])) nearest = false;
                        }
                    }
                }
            }
            if (nearest) {
                res += sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            }
        }
    }
    cout << llround(res);
    return 0;
}