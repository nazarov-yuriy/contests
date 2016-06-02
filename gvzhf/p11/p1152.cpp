#include <iostream>

using namespace std;

struct fr {
    char m[20];
};
int n;

int rec(fr f, int s) {
    if(s == 0) return 0;
    int res = 2000000009;
    for (int i = 0; i < n; i++) {
        if (f.m[(i + 0) % n] && f.m[(i + 1) % n] && f.m[(i + 2) % n]) {
            fr fc = f;
            fc.m[(i + 0) % n] = 0;
            fc.m[(i + 1) % n] = 0;
            fc.m[(i + 2) % n] = 0;
            int sc = s - f.m[(i + 0) % n] - f.m[(i + 1) % n] - f.m[(i + 2) % n];
            res = min(res, sc + rec(fc, sc));
        }
    }
    if(res < 2000000009) return res;
    for (int i = 0; i < n; i++) {
        if (f.m[(i + 0) % n] && f.m[(i + 1) % n]) {
            fr fc = f;
            fc.m[(i + 0) % n] = 0;
            fc.m[(i + 1) % n] = 0;
            int sc = s - f.m[(i + 0) % n] - f.m[(i + 1) % n];
            res = min(res, sc + rec(fc, sc));
        }
    }
    if(res < 2000000009) return res;
    for (int i = 0; i < n; i++) {
        if (f.m[(i + 0) % n]) {
            fr fc = f;
            fc.m[(i + 0) % n] = 0;
            int sc = s - f.m[(i + 0) % n];
            res = min(res, sc + rec(fc, sc));
        }
    }
    return res;
}

int main() {
    cin >> n;
    fr frame0 = {{}};
    int s = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        frame0.m[i] = t;
        s += frame0.m[i];
    }
    cout << rec(frame0, s);
    return 0;
}