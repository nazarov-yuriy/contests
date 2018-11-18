#include <iostream>
#include <assert.h>
#include <set>
#include <map>
#include <vector>

using namespace std;
#define POW 15

struct Node {
    map<int, int> links;
    int parents[POW];
    int depth;
    int weight;
    int sum_weight;
};

int main() {
    Node nodes[50000] = {{}};
    int n, m, u, v, w;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        nodes[u].links[v] = w;
        nodes[v].links[u] = w;
    }

    nodes[0].depth = 1;
    set<int> front = {0};
    while (!front.empty()) {
        set<int> next_front = {};
        for (auto &parent : front) {
            for (auto &link : nodes[parent].links) {
                if (nodes[link.first].depth == 0) {
                    nodes[link.first].parents[0] = parent;
                    nodes[link.first].depth = nodes[parent].depth + 1;
                    nodes[link.first].weight = link.second;
                    nodes[link.first].sum_weight = nodes[link.first].weight + nodes[parent].sum_weight;

                    next_front.insert(link.first);
                }
            }
        }
        front = next_front;
    }
    for (int p = 1; p < POW; p++) {
        for (int i = 0; i < n; i++) {
            nodes[i].parents[p] = nodes[nodes[i].parents[p - 1]].parents[p - 1];
        }
    }
//    for (int i = 0; i < n; i++) {
//        cout << i << ": " << nodes[i].parent << " " << nodes[i].weight << endl;
//    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        int res = 0;
        for (int p = POW - 1; p >= 0; p--) {
            while (nodes[u].depth >= nodes[v].depth + (1 << p)) {
                int next_u = nodes[u].parents[p];
                res += nodes[u].sum_weight - nodes[next_u].sum_weight;
                u = next_u;
            }
            while (nodes[v].depth >= nodes[u].depth + (1 << p)) {
                int next_v = nodes[v].parents[p];
                res += nodes[v].sum_weight - nodes[next_v].sum_weight;
                v = next_v;
            }
        }

        for (int p = POW - 1; p >= 0; p--) {
            int new_u = nodes[u].parents[p];
            int new_v = nodes[v].parents[p];
            if (new_u != new_v) {
                res += nodes[u].sum_weight - nodes[new_u].sum_weight + nodes[v].sum_weight - nodes[new_v].sum_weight;
                u = new_u;
                v = new_v;
            }
        }
        while (u != v) {
            res += nodes[u].weight + nodes[v].weight;
            u = nodes[u].parents[0];
            v = nodes[v].parents[0];
        }
        cout << res << endl;
    }
    return 0;
}