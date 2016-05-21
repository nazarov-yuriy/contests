#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int w, h;
    cin >> w >> h;
    char map[h + 2][w + 2] = {};
    long long sum_x = 0, sum_y = 0, xy_cnt = 0;
    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            while ('0' > (map[y][x] = getchar())) { }
            map[y][x] = map[y][x] == '1';
            if (map[y][x]) {
                sum_x += x;
                sum_y += y;
                xy_cnt++;
            }
        }
    }
    double max_ll = 0, min_ll = 1000000000;
    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            if (map[y][x] && (!map[y][x - 1] || !map[y][x + 1] || !map[y - 1][x] || !map[y + 1][x])) {
                min_ll = min(min_ll, (1.0 * x - 1.0 * sum_x / xy_cnt) * (1.0 * x - 1.0 * sum_x / xy_cnt) +
                                     (1.0 * y - 1.0 * sum_y / xy_cnt) * (1.0 * y - 1.0 * sum_y / xy_cnt));
                max_ll = max(max_ll, (1.0 * x - 1.0 * sum_x / xy_cnt) * (1.0 * x - 1.0 * sum_x / xy_cnt) +
                                     (1.0 * y - 1.0 * sum_y / xy_cnt) * (1.0 * y - 1.0 * sum_y / xy_cnt));
            }
        }
    }
    double t2 = fabs(2 * min_ll - max_ll) / max_ll;
    double t1 = fabs(max_ll - min_ll) / max_ll;
    if (t2 < 0.2) {
        cout << "square";
    } else if (t1 < 0.2) {
        cout << "circle";
    } else {
        cout << "triangle";
    }
    return 0;
}