#include <iostream>
#include <set>

using namespace std;

#define UND 0
#define LOS 1
#define WIN 2

char d[10001] = {};
set<int> k;

char def(int n) {
    if (n < *k.begin()) return UND;
    if (d[n]) return d[n];
    if (n == *k.begin()) return LOS;
    char res = LOS;
    for (auto it = k.begin(); it != k.end(); ++it) {
        if (def(n - *it) == LOS)
            res = WIN;
    }
    return d[n] = res;
}

int main() {
    int n, m, t;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        k.insert(t);
    }
    if (def(n) == WIN) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
    return 0;
}