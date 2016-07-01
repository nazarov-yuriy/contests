#include <iostream>
#include <map>
#include <set>

using namespace std;

struct node {
    int parent;
    int count;
    set<int> children;
};

int main() {
    int n, q;
    map<int, node> nodes;
    cin >> n >> q;
    nodes[1] = {0, 0};
    for (int i = 1; i < n; i++) {
        int parent, child, count;
        cin >> parent >> child >> count;
        if (!nodes.count(parent)) {
            int t = parent;
            parent = child;
            child = t;
        }
        nodes[child] = {parent, count};
        do {
            nodes[parent].children.insert(child);
            nodes[parent].count += count;
            parent = nodes[parent].parent;
        } while (parent != 0);
    }
    int to_remove = n - 1 - q;
    while (to_remove) {
        long double min_count = 10000000000000.0;
        int min_index = 1;
        auto it = nodes.begin();
        ++it;
        for (; it != nodes.end(); ++it) {
            if (it->second.children.size() + 1 <= to_remove && min_count > it->second.count / (it->second.children.size() + 1.0)) {
                min_count = it->second.count / (it->second.children.size() + 1.0);
                min_index = it->first;
            }
        }
        int parent = nodes[min_index].parent;
        do {
            for (auto jt = nodes[min_index].children.begin(); jt != nodes[min_index].children.end(); ++jt) nodes[parent].children.erase(*jt);
            nodes[parent].children.erase(min_index);
            nodes[parent].count -= nodes[min_index].count;
            parent = nodes[parent].parent;
        } while (parent != 0);
        to_remove -= nodes[min_index].children.size() + 1;
        for (auto jt = nodes[min_index].children.begin(); jt != nodes[min_index].children.end(); ++jt) nodes.erase(*jt);

        nodes.erase(min_index);
    }
    cout << nodes[1].count;
    return 0;
}