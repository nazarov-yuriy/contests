#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, re, rk, m;
    cin >> n;
    set<string> t2, t3;
    for (int i = 0; i < n; i++) {
        string a, b, c;
        int cnt;
        cin >> cnt;
        cin >> a;
        if(cnt > 1) cin >> b;
        if (cnt == 3) {
            cin >> c;
            if (a != "Efremov" && a != "Kantorov") t3.insert(a);
            if (b != "Efremov" && b != "Kantorov") t3.insert(b);
            if (c != "Efremov" && c != "Kantorov") t3.insert(c);
        } else {
            if (a != "Efremov" && a != "Kantorov") t2.insert(a);
            if (b != "Efremov" && b != "Kantorov") t2.insert(b);
        }
    }
    cin >> re >> rk;
    cin >> m;
    int max_r = 0;
    string max_name;
    for (int i = 0; i < m; i++) {
        string name;
        int r;
        cin >> name >> r;
        if (t3.count(name)) {
            if (!t2.count(name)) {
                if (rk + r > max_r) {
                    max_r = rk + r;
                    max_name = name;
                }
            }
        } else {
            if (re + rk + r > max_r) {
                max_r = re + rk + r;
                max_name = name;
            }
        }
    }
    if (max_r) {
        cout << "Win" << endl << max_name;
    } else {
        cout << "Fail";
    }
    return 0;
}
