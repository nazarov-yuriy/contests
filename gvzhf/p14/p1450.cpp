#include <iostream>
#include <vector>

using namespace std;

struct to_cost {
    int from;
    int to;
    int cost;
};

int main() {
    int n, m, s, f;
    cin >> n >> m;
    int total_cost[n + 1] = {};
    vector<to_cost> v;
    for (int i = 1; i <= n; i++) { total_cost[i] = 2000000000; }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    cin >> s >> f;
    total_cost[s] = 0;
    for (int i = 1; i <= n; i++) {
        bool changed = false;
        for (auto it = v.begin(); it != v.end(); ++it) {
            if (total_cost[it->to] > total_cost[it->from] - it->cost) {
                total_cost[it->to] = total_cost[it->from] - it->cost;
                changed = true;
            }
        }
        if (!changed) break;
    }
    if (total_cost[f] > 0) {
        cout << "No solution";
    } else {
        cout << -total_cost[f];
    }
    return 0;
}
