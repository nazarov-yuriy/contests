#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> stack, input;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        input.push_back(t);
    }
    int need = n;
    for (auto it = input.rbegin(); it != input.rend(); ++it) {
        stack.push_back(*it);
        while (stack.size() && stack.back() == need) {
            stack.pop_back();
            need--;
        }
    }
    cout << (stack.size() ? "Cheater" : "Not a proof");
    return 0;
}