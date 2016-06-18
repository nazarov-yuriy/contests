#include <iostream>
#include <unordered_set>

using namespace std;

struct node {
    unordered_set<int> children;
    unordered_set<int> links;
    int parent;
    int deep;
};
#define L 105
int gw;

static inline int id(int x, int y) {
    return gw * (y / 2) + x / 2;
}

unordered_set<int> conn[L * L];

static inline int links(string map[], int x, int y) {
    int cnt = 0;
    if (map[y][x - 1] == '-') {
        cnt++;
        conn[id(x, y)].insert(id(x - 2, y));
    } else if (map[y][x - 1] != ' ') {
        return -1;
    }
    if (map[y][x + 1] == '-') {
        cnt++;
        conn[id(x, y)].insert(id(x + 2, y));
    } else if (map[y][x + 1] != ' ') {
        return -1;
    }
    if (map[y - 1][x] == '|') {
        cnt++;
        conn[id(x, y)].insert(id(x, y - 2));
    } else if (map[y - 1][x] != ' ') {
        return -1;
    }
    if (map[y + 1][x] == '|') {
        cnt++;
        conn[id(x, y)].insert(id(x, y + 2));
    } else if (map[y + 1][x] != ' ') {
        return -1;
    }
    if (map[y - 1][x - 1] == '\\') {
        cnt++;
        conn[id(x, y)].insert(id(x - 2, y - 2));
    } else if (map[y - 1][x - 1] != ' ' && map[y - 1][x - 1] != '/') {
        return -1;
    }
    if (map[y - 1][x + 1] == '/') {
        cnt++;
        conn[id(x, y)].insert(id(x + 2, y - 2));
    } else if (map[y - 1][x + 1] != ' ' && map[y - 1][x + 1] != '\\') {
        return -1;
    }
    if (map[y + 1][x - 1] == '/') {
        cnt++;
        conn[id(x, y)].insert(id(x - 2, y + 2));
    } else if (map[y + 1][x - 1] != ' ' && map[y + 1][x - 1] != '\\') {
        return -1;
    }
    if (map[y + 1][x + 1] == '\\') {
        cnt++;
        conn[id(x, y)].insert(id(x + 2, y + 2));
    } else if (map[y + 1][x + 1] != ' ' && map[y + 1][x + 1] != '/') {
        return -1;
    }
    return cnt;
}

static bool check(string map[], int w, int h) {
    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            if (1 == x % 2 && 1 == y % 2) {
                if (map[y][x] != 'O')
                    return false;
                if (3 != links(map, x, y))
                    return false;
            } else {
                if (map[y][x] == 'O')
                    return false;
            }
        }
    }
    return true;
}

node tree[L * L];
int comp_num = 1;
int comp_id[L * L] = {0};

void mark(int a, int b, int n) {
    int t = ++comp_num;
    unordered_set<int> reid;
    while (tree[a].deep > tree[b].deep) {
        if (comp_id[a]) reid.insert(comp_id[a]);
        comp_id[a] = t;
        a = tree[a].parent;
    }
    while (tree[b].deep > tree[a].deep) {
        if (comp_id[b]) reid.insert(comp_id[b]);
        comp_id[b] = t;
        b = tree[b].parent;
    }
    while (a != b) {
        if (comp_id[a]) reid.insert(comp_id[a]);
        comp_id[a] = t;
        a = tree[a].parent;
        if (comp_id[b]) reid.insert(comp_id[b]);
        comp_id[b] = t;
        b = tree[b].parent;
    }
    if (comp_id[a]) reid.insert(comp_id[a]);
    comp_id[a] = t;
    if (!reid.empty()) {
        for (int i = 0; i < n; i++) {
            if (reid.count(comp_id[i])) comp_id[i] = t;
        }
    }
}

int main() {
    int w, h;
    cin >> w >> h;
    gw = w / 2 + 1;
    string map[h + 2];
    getline(cin, map[0]);
    map[h + 1] = map[0] = "                                                                                                              ";
    for (int i = 1; i <= h; i++) {
        getline(cin, map[i]);
        map[i] = " " + map[i] + " ";
    }
    if (w % 2 != 1 || h % 2 != 1) {
        cout << "Just a picture";
        return 0;
    }
    if (!check(map, w, h)) {
        cout << "Just a picture";
        return 0;
    }
    unordered_set<int> queue, visited;
    queue.insert(id(1, 1));
    tree[id(1, 1)].parent = -1;
    tree[id(1, 1)].deep = 0;
    while (!queue.empty()) {
        int el = *queue.begin();
        queue.erase(el);
        visited.insert(el);
        for (auto it = conn[el].begin(); it != conn[el].end(); ++it) {
            if (!visited.count(*it)) {
                queue.insert(*it);
                tree[*it].parent = el;
                tree[*it].deep = tree[el].deep + 1;
                tree[el].children.insert(*it);
            } else if (tree[el].parent != *it) {
                tree[el].links.insert(*it);
            }
        }
    }
    if (visited.size() != (w / 2 + 1) * (h / 2 + 1)) {
        cout << "Just a picture";
        return 0;
    }
    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            if (1 == x % 2 && 1 == y % 2) {
                for (auto it = tree[id(x, y)].links.begin(); it != tree[id(x, y)].links.end(); ++it) {
                    mark(id(x, y), *it, id(w, h));
                }
            }
        }
    }
    for (int i = 0; i < id(w, h); i++) {
        if (comp_id[i] != comp_num) {
            cout << "Just a picture";
            return 0;
        }
    }
    cout << "Island world";
    return 0;
}