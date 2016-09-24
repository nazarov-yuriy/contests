#include <iostream>
#include <vector>

using namespace std;

struct segment {
    int l;
    int r;
    int id;
};

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    vector<segment> input, stack;
    vector<int> queries;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        input.push_back({a, b, i + 1});
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        queries.push_back(t);
    }
    auto qit = queries.begin();
    stack.push_back({-1, 2000000000, -1});
    input.push_back({1000000007, 1000000009, -1});
    for (auto it = input.begin(); it != input.end(); ++it) {
        while (it->r > stack.back().r) {
            while (qit != queries.end() && *qit <= stack.back().r) {
                cout << stack.back().id << endl;
                ++qit;
            }
            stack.pop_back();
        }
        while (qit != queries.end() && *qit < it->l && *qit <= stack.back().r) {
            cout << stack.back().id << endl;
            ++qit;
        }
        stack.push_back(*it);
    }
    return 0;
}