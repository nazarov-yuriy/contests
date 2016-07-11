#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
int sparent[100004];
int srank[100004];

void make_set(int v) {
    sparent[v] = v;
    srank[v] = 0;
}

int find_set(int v) {
    if (v == sparent[v])
        return v;
    return sparent[v] = find_set(sparent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (srank[a] < srank[b])
            swap(a, b);
        sparent[b] = a;
        if (srank[a] == srank[b])
            ++srank[a];
    }
}

int main() {
    int n, m, q, a, b;
    cin >> n >> m;
    vector<pair<int, int>> inp;
    vector<int> cut, res;
    unordered_set<int> exc;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        pair<int, int> p(a, b);
        inp.push_back(p);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a;
        a--;
        cut.push_back(a);
        exc.insert(a);
    }
    for (int i = 0; i < n; i++) {
        make_set(i + 1);
    }
    int components = n;
    for (int i = 0; i < m; i++) {
        if (!exc.count(i) && find_set(inp[i].first) != find_set(inp[i].second)) {
            components--;
            union_sets(inp[i].first, inp[i].second);
        }
    }
    for (int j = q - 1; j >= 0; j--) {
        int i = cut[j];
        res.push_back(components);
        if (find_set(inp[i].first) != find_set(inp[i].second)) {
            components--;
            union_sets(inp[i].first, inp[i].second);
        }
    }
    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        cout << *it << ' ';
    }
    return 0;
}