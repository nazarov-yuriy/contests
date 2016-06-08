#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct edge {
    int to, length;
};

int dijkstra(const vector<vector<edge> > &graph, int source0, int source1, int target0, int target1) {
    int to_visited = -1;
    vector<int> min_distance(graph.size(), 2000000000);
    min_distance[source0] = 0;
    min_distance[source1] = 0;
    set<pair<int, int> > active_vertices;
    active_vertices.insert({0, source0});
    active_vertices.insert({0, source1});

    while (!active_vertices.empty()) {
        int where = active_vertices.begin()->second;
        if (where == target0 || where == target1) {
            if (to_visited >= 0)
                return min(min_distance[where], min_distance[to_visited]);
            else
                to_visited = where;
        }
        active_vertices.erase(active_vertices.begin());
        for (auto edge : graph[where])
            if (min_distance[edge.to] > min_distance[where] + edge.length) {
                active_vertices.erase({min_distance[edge.to], edge.to});
                min_distance[edge.to] = min_distance[where] + edge.length;
                active_vertices.insert({min_distance[edge.to], edge.to});
            }
    }
    return 2000000000;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> graph;
    for (int i = 0; i < 2 * n; i++) graph.push_back({});
    for (int i = 0; i < m; i++) {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        if (graph[2 * f + 0].empty()) graph[2 * f + 0].push_back({2 * f + 1, 1});
        if (graph[2 * f + 1].empty()) graph[2 * f + 1].push_back({2 * f + 0, 1});
        if (graph[2 * t + 0].empty()) graph[2 * t + 0].push_back({2 * t + 1, 1});
        if (graph[2 * t + 1].empty()) graph[2 * t + 1].push_back({2 * t + 0, 1});
        graph[2 * f + 1].push_back({2 * t + 1, 0});
        graph[2 * t + 0].push_back({2 * f + 0, 0});
    }
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    cout << dijkstra(graph, 2 * f + 0, 2 * f + 1, 2 * t + 0, 2 * t + 1);
    return 0;
}