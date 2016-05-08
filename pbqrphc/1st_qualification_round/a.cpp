#include <iostream>

using namespace std;

void one(int &add_cnt) {
    cout << "1";
    while (add_cnt) {
        cout << "1";
        add_cnt--;
    }
}

void zero(int &add_cnt) {
    cout << "0";
    while (add_cnt) {
        cout << "0";
        add_cnt--;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b == 0 && c == 0) {
            if (a != 0 && d != 0) {
                cout << "impossible";
            } else {
                if(a) zero(a);
                if(d) one(d);
            }
        } else {
            if (b > c) {
                if (b > c + 1) {
                    cout << "impossible";
                } else {
                    zero(a);
                    while (b || c) {
                        if (b && b--) one(d);
                        if (c && c--) zero(a);
                    }
                }
            } else {
                if (c > b + 1) {
                    cout << "impossible";
                } else {
                    one(d);
                    while (b || c) {
                        if (c && c--) zero(a);
                        if (b && b--) one(d);
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}