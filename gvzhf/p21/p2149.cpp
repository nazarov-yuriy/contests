#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    int pigeons[n] = {0};
    cin >> s;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i * 5 + 3] == '>') {
            pigeons[i] = 1;
        } else {
            pigeons[i] = 0;
        }
        sum += pigeons[i];
    }
    cin >> s >> s;
    int even_r = 0;
    int min_rl_lr = n;
    int sum_i = 0;
    for (int i = 0; i < n; i++) {
        sum_i += pigeons[i];
        if (i == (n/2 - 1)) { // hack to solve specific case by generic solution
            int lr = sum_i + ((n - 1 - i) - (sum - sum_i));
            int rl = (i + 1 - sum_i) + (sum - sum_i);
            min_rl_lr = min(min_rl_lr, min(rl, lr));
        }
        if (pigeons[i] == (i % 2)) {
            even_r++;
        }
    }
    cout << min(min(even_r, n - even_r), min_rl_lr) << endl;
    return 0;
}