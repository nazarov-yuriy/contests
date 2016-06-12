#include <iostream>
#include <algorithm>

using namespace std;

struct city {
    int x;
    int y;
    int id;
};

bool cmp(city a, city b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    int n;
    cin >> n;
    vector<city> c;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].x >> c[i].y;
        c[i].id = i + 1;
    }
    sort(c.begin(), c.end(), cmp);
    for (int i = 0; i < n / 2; i++) {
        cout << c[2 * i + 0].id << ' ' << c[2 * i + 1].id << endl;
    }
    return 0;
}