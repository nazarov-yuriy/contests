#include <iostream>
#include <cmath>

using namespace std;

long double eps = 0.0000001;

bool check(long double w, long double h, long double H, long double L) {
    if (w <= L + eps && h <= H + eps) {
        return true;
    }
    if (h <= L) {
        long double x = sqrt(L * L - h * h);
        if (h * x + w * h <= L * H + eps) {
            return true;
        }
    }
    return false;
}

int main() {
    long double w, h;
    int n;
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++) {
        long double H, L;
        cin >> H >> L;
        if (check(w, h, H, L) || check(h, w, H, L)) {
            cout << "Block the hole" << endl;
        } else {
            cout << "Too small" << endl;
        }
    }
    return 0;
}