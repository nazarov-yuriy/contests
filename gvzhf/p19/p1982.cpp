#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set<int> connected;
    int costs[n][n];
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        connected.insert(--t);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> costs[i][j];
        }
    }

    int total_cost = 0;
    while (connected.size() != n) {
        int min_cost = 999999, min_from = 0, min_to = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(connected.count(i) && !connected.count(j) && min_cost > costs[i][j]){
                    min_cost = costs[i][j];
                    min_from = i;
                    min_to = j;
                }
            }
        }
        total_cost += min_cost;
        connected.insert(min_to);
    }
    cout << total_cost;
    return 0;
}