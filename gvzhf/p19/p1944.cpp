#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> points;
    int miny = 101, maxy = -101, minx = 101, maxx = -101;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        maxx = max(maxx, x);
        maxy = max(maxy, y);
        minx = min(minx, x);
        miny = min(miny, y);
        points.insert((x + 100) * 201 + (y + 100));
    }

    for (int y = max(0, maxy); y >= min(0, miny); y--) {
        for (int x = min(minx, 0); x <= max(maxx, 0); x++) {
            if (points.count((x + 100) * 201 + (y + 100))) {
                cout << '*';
            } else if (x == 0 && y == 0) {
                cout << '+';
            } else if (x == 0) {
                cout << '|';
            } else if (y == 0) {
                cout << '-';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}