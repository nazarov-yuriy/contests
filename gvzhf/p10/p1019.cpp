#include <iostream>
#include <list>

using namespace std;

struct interval {
    int from;
    int to;
    char color;
};

int main() {
    int n;
    cin >> n;
    list <interval> colors;
    colors.push_back({0, 1000000000, 'w'});
    for (int i = 0; i < n; i++) {
        int f, t;
        char c;
        cin >> f >> t >> c;
        auto fit = colors.begin();
        auto tit = colors.begin();
        for (auto it = colors.begin(); it != colors.end(); ++it) {
            if (it->from <= f && f <= it->to) fit = it;
            if (it->from <= t && t <= it->to) tit = it;
        }
        if (fit == tit) {
            fit = colors.insert(tit, *tit);
        } else {
            auto fit1 = fit;
            fit1++;
            if (fit1 != tit) {
                colors.erase(fit1, tit);
            }
        }
        if (c == fit->color) f = fit->from;
        if (c == tit->color) t = tit->to;
        fit->to = f;
        tit->from = t;
        colors.insert(tit, {f, t, c});
        if (fit->from == fit->to) colors.erase(fit);
        if (tit->from == tit->to) colors.erase(tit);
        for (auto it = colors.begin(); it != colors.end();) {
            auto next = it;
            next++;
            if (next != colors.end()) {
                if (next->color == it->color) {
                    it->to = next->to;
                    colors.erase(next);
                } else {
                    ++it;
                }
            } else {
                break;
            }
        }
    }
    int max_l = -1, max_f = 0, max_t = 0;
    for (auto it = colors.begin(); it != colors.end(); ++it) {
        if (it->color == 'w' && it->to - it->from > max_l) {
            max_l = it->to - it->from;
            max_f = it->from;
            max_t = it->to;
        }
    }
    cout << max_f << ' ' << max_t;
    return 0;
}