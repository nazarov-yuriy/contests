#include <iostream>

using namespace std;

int main() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    int xa = min(a, x); // use pool a
    a -= xa;
    x -= xa;
    int yb = min(b, y); // use pool b
    b -= yb;
    y -= yb;
    int xc = min(c, x); // use pool c
    c -= xc;
    x -= xc;
    int yc = min(c, y); // use pool c
    c -= yc;
    y -= yc;
    if ((x == 0) && (y == 0) && (z <= a + b + c)) {
        cout << "It is a kind of magic" << endl;
    } else {
        cout << "There are no miracles in life" << endl;
    }
    return 0;
}