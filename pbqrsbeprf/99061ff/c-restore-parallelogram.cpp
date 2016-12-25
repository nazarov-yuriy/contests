#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct pt {
    int x;
    int y;

    inline pt operator-(pt a) {
        return {x - a.x, y - a.y};
    }

    inline pt operator+(pt a) {
        return {a.x + x, a.y + y};
    }

    bool operator==(const pt &a) const {
        return (a.x == x) && (a.y == y);
    }
};
namespace std {
    template<>
    struct hash<pt> {
        std::size_t operator()(const pt &k) const {
            return (k.y + 1000) * 2002 + k.x + 1000;
        }
    };
}

int main() {
    vector<pt> pts(3);
    unordered_set<pt> res;
    for (int i = 0; i < 3; i++) {
        cin >> pts[i].x >> pts[i].y;
    }
    for (int i = 0; i < 3; i++) {
        pt diff = pts[(i + 2) % 3] - pts[(i + 1) % 3];
        res.insert(pts[i] + diff);
        res.insert(pts[i] - diff);
    }
    cout << res.size() << endl;
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << it->x << ' ' << it->y << endl;
    }
    return 0;
}