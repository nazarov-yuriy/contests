#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
    int intrs;
};

bool cmp(point a, point b) {
    return a.x < b.x;
}

bool intersects(point a, point b) {
    if (a.x < b.x && b.x < a.y) return true;
    if (a.x < b.y && b.y < a.y) return true;
    if (b.x < a.x && a.x < b.y) return true;
    if (b.x < a.y && a.y < b.y) return true;
    return (a.x == b.x && a.y == b.y);
}

int main() {
    int n;
    cin >> n;
    vector<point> points;
    for (int i = 0; i < n; i++) {
        points.push_back({0, 0, 0});
        cin >> points[i].x >> points[i].y;
        if (points[i].x > points[i].y) swap(points[i].x, points[i].y);
    }
    sort(points.begin(), points.end(), cmp);
    for (auto it = points.begin(); it != points.end();) {
        auto next = it + 1;
        if (next != points.end() && it->x == next->x && it->y == next->y) {
            it = points.erase(next);
        } else {
            it = next;
        }
    }
    bool intrs_found = false;
    n = points.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (intersects(points[i], points[j])) {
                points[i].intrs++;
                points[j].intrs++;
                intrs_found = true;
            }
        }
    }
    while (intrs_found) {
        intrs_found = false;
        int max_intrs = 0;
        auto max_pos = points.begin();
        for (auto it = points.begin(); it != points.end(); ++it) {
            if (it->intrs >= max_intrs) {
                max_intrs = it->intrs;
                max_pos = it;
            }
        }
        if (max_intrs) {
            for (auto it = points.begin(); it != points.end(); ++it) {
                if (it != max_pos && intersects(*it, *max_pos)) it->intrs--;
            }
            points.erase(max_pos);
            intrs_found = true;
        }
    }
    cout << points.size() << endl;
    for (auto it = points.begin(); it != points.end(); ++it) {
        cout << it->x << ' ' << it->y << endl;
    }
    return 0;
}