#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
#define EPS 0.00000000001

struct pt {
    double x;
    double y;
};

double len(pt a, pt b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double space(pt a, pt b, pt c) {
    double ab = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    double ac = sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
    double bc = sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
    return sqrt(max(0.0, (ab + ac + bc) * (ab + ac - bc) * (ab + bc - ac) * (bc + ac - ab))) / 4;
}

double space(vector<pt> &pts) {
    double res = 0;
    for (int i = 2; i < pts.size(); ++i) {
        res += space(pts[0], pts[i - 1], pts[i - 0]);
    }
    return res;
}

template<typename T>
typename T::iterator ic(typename T::iterator it, T &c, int n) {
    for (int i = 0; i < n; i++)
        if (++it == c.end())
            it = c.begin();
    return it;
}

pair<vector<pt>::iterator, pt> anti(vector<pt> &pts, int i, pt f, double full) {
    auto bg = pts.begin();
    double s = 0, lasts = 0;
    int added = 0;
    for (; s < full / 2 - EPS; added++) {
        lasts = space(f, *ic(bg, pts, i + added + 1), *ic(bg, pts, i + added + 2));
        s += lasts;
    }
    if (s > full / 2 + EPS) {
        double p = (s - full / 2) / lasts;
        double x = p * ic(bg, pts, i + added)->x + (1 - p) * ic(bg, pts, i + added + 1)->x;
        double y = p * ic(bg, pts, i + added)->y + (1 - p) * ic(bg, pts, i + added + 1)->y;
        return pair<vector<pt>::iterator, pt>(ic(bg, pts, i + added + 1), {x, y});
    } else {
        return pair<vector<pt>::iterator, pt>(pts.end(), *ic(bg, pts, i + added + 1));
    }
}

int main() {
    unsigned int n;
    cin >> n;
    vector<pt> pts(n);
    for (auto &it : pts) {
        cin >> it.x >> it.y;
    }
    double full = space(pts);
    if (full < EPS) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < pts.size(); i++) { //size may grow
        auto it_pt = anti(pts, i, *ic(pts.begin(), pts, i), full);
        if (it_pt.first != pts.end()) {
            pts.insert(it_pt.first, it_pt.second);
        }
    }
    double res = 400.0;
    for (int i = 0; i < pts.size(); i++) {
        double l = 0, r = 1;
        while (r - l > EPS) {
            double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3, x, y;
            x = ic(pts.begin(), pts, i + 1)->x * m1 + ic(pts.begin(), pts, i)->x * (1 - m1);
            y = ic(pts.begin(), pts, i + 1)->y * m1 + ic(pts.begin(), pts, i)->y * (1 - m1);
            auto it_pt_m1 = anti(pts, i, {x, y}, full);
            double fm1 = len({x, y}, it_pt_m1.second);

            x = ic(pts.begin(), pts, i + 1)->x * m2 + ic(pts.begin(), pts, i)->x * (1 - m2);
            y = ic(pts.begin(), pts, i + 1)->y * m2 + ic(pts.begin(), pts, i)->y * (1 - m2);
            auto it_pt_m2 = anti(pts, i, {x, y}, full);
            double fm2 = len({x, y}, it_pt_m2.second);

            if (fm1 > fm2)
                l = m1;
            else
                r = m2;
        }
        double p = (l + r) / 2;
        double x = ic(pts.begin(), pts, i + 1)->x * p + ic(pts.begin(), pts, i)->x * (1 - p);
        double y = ic(pts.begin(), pts, i + 1)->y * p + ic(pts.begin(), pts, i)->y * (1 - p);
        auto it_pt = anti(pts, i, {x, y}, full);
        res = min(res, len({x, y}, it_pt.second));
    }
    cout << fixed << setprecision(4) << res;
    return 0;
}