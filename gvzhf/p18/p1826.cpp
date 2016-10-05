#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }
    sort(inp.begin(), inp.end());
    if (inp.size() == 2) {
        cout << inp[1];
    } else if (inp.size() == 3) {
        cout << inp[0] + inp[1] + inp[2];
    } else {
        int a = inp[0], b = inp[1];
        int res = b;
        while (inp.size() > 3) {
            int d = inp.back();
            inp.pop_back();
            int c = inp.back();
            inp.pop_back();
            res += min(
                    b + d + a + b,
                    a + c + a + d
            );
        }
        if (inp.size() > 2) {
            res += a + inp.back();
        }
        cout << res;
    }
    return 0;
}