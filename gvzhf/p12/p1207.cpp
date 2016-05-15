#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct xy {
    int x;
    int y;
    int n;
};

bool cmp(xy a, xy b) {
    return ((long long) a.x * (long long) b.y) > ((long long) b.x * (long long) a.y);
}

int main() {
    int n;
    cin >> n;
    vector<xy> points;
    int maxy = -2000000000, x_of_maxy = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y >= maxy) {
            maxy = y;
            x_of_maxy = x;
        }
        points.push_back({x, y, i});
    }
    int first, second;
    for (auto it = points.begin(); it != points.end();) {
        if (it->x == x_of_maxy && it->y == maxy) {
            first = it->n;
            it = points.erase(it);
        } else {
            it->x = it->x - x_of_maxy;
            it->y = maxy - it->y;
            ++it;
        }
    }
    sort(points.begin(), points.end(), cmp);
    second = points[points.size() / 2].n;
    cout << first + 1 << ' ' << second + 1;
    return 0;
}