#include <iostream>
#include <map>

using namespace std;

struct state {
    int left;
    int right;
    int cnt;
    long long int lt;
    long long int rt;
};

int main() {
    int n;
    cin >> n;
    map<int, state> states;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        states[t].left = states[t].left ? min(i, states[t].left) : i;
        states[t].right = states[t].right ? max(i, states[t].right) : i;
        states[t].cnt++;
    }
    state prev = {1, 1, 0, 0, 0};
    for (auto it = states.begin(); it != states.end(); ++it) {
        it->second.lt = it->second.cnt + it->second.right - it->second.left + min(
                abs(prev.left - it->second.right) + prev.lt,
                abs(prev.right - it->second.right) + prev.rt
        );
        it->second.rt = it->second.cnt + it->second.right - it->second.left + min(
                abs(prev.left - it->second.left) + prev.lt,
                abs(prev.right - it->second.left) + prev.rt
        );
        prev = it->second;
    }
    cout << min(states.rbegin()->second.lt, states.rbegin()->second.rt);
    return 0;
}