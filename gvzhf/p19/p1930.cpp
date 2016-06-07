#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct city {
    bool visited;
    int dist;
    map<int, int> to;
};

bool cmp(city *a, city *b) {
    return a->dist > b->dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    city c[2 * n + 2];
    for (int i = 1; i <= n; i++) {
        c[2 * i] = c[2 * i + 1] = {false, 2000000000};
        c[2 * i].to[2 * i + 1] = 1;
        c[2 * i + 1].to[2 * i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int f, t;
        cin >> f >> t;
        c[2 * f + 1].to[2 * t + 1] = 0;
        c[2 * t + 0].to[2 * f + 0] = 0;
    }
    int f, t;
    cin >> f >> t;
    c[2 * f].dist = c[2 * f + 1].dist = 0;
    vector<city *> cl;
    for (int i = 2; i <= 2 * n + 1; i++) cl.push_back(&c[i]);
    while (true){//!cl.empty()) {
        city *current = NULL;// = cl.front();
        int min_d = 2000000001;
        for(auto it = cl.begin(); it != cl.end(); ++it){if(!(*it)->visited && (*it)->dist < min_d){current = *it; min_d = (*it)->dist;}}
        if (current == NULL) break;
        //pop_heap(cl.begin(), cl.end());
        //cl.pop_back();
        for (auto it = current->to.begin(); it != current->to.end(); ++it) {
            int dist = current->dist + it->second;
            if (dist < c[it->first].dist) {
                c[it->first].dist = dist;
                //make_heap(cl.begin(), cl.end(), cmp);
            }
        }
        current->visited = true;
    }
    cout << min(c[2 * t].dist, c[2 * t + 1].dist);
    return 0;
}