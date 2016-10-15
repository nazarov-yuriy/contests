#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#ifndef M_PI
# define M_PI		3.14159265358979323846	/* pi */
#endif

using namespace std;

struct point {
    double x;
    double y;
};

bool cmp(point a, point b) {
    if (b.x > a.x) return true;
    if ((b.x == a.x) && (b.y > a.y)) return true;
    return false;
}

bool cw(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

int main() {
    int n;
    double r;
    cin >> n >> r;
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p.begin(), p.end(), cmp);
    point p1 = p[0];
    point p2 = p.back();
    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p1);


    for (int i = 0; i < n; i++) {
        if (i == n - 1 || cw(p1, p[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], p[i]))
                up.pop_back();
            up.push_back(p[i]);
        }
        if (i == n - 1 || ccw(p1, p[i], p2)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], p[i]))
                down.pop_back();
            down.push_back(p[i]);
        }
    }
    p.clear();
    for (auto it = up.begin(); it != up.end(); ++it) {
        p.push_back(*it);
    }
    for (auto it = down.rbegin(); it != down.rend(); ++it) {
        p.push_back(*it);
    }
    double res = r * 2.0 * M_PI;
    for (int i = 0; i < p.size(); i++) {
        point a = p[i], b = p[(i + 1) % p.size()];
        res += sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    cout << llround(res);
    return 0;
}