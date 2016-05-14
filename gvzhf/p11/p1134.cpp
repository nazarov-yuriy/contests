#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int visited[n + 2] = {};
    vector<int> numbers;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        numbers.push_back(t);
    }
    sort(numbers.begin(), numbers.end(), std::less<int>());
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it > n) {
            cout << "NO";
            return 0;
        }
        if (*it == 0 || visited[*it]) {
            if (visited[*it + 1] || *it + 1 > n) {
                cout << "NO";
                return 0;
            } else {
                visited[*it + 1] = 1;
            }
        } else {
            visited[*it] = 1;
        }
    }
    cout << "YES";
    return 0;
}