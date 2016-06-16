#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, p, t, coins = 0, casts = 0, current_coins = 0;
    cin >> n >> p;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> t;
        cnt[t]++;
    }
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        if ((current_coins + it->second) * it->first <= p) {
            current_coins += it->second;
        } else {
            coins += current_coins;
            casts += current_coins != 0;
            if (it->first * it->second > p) {
                current_coins = 0;
                break;
            }
            current_coins = it->second;
        }
    }
    coins += current_coins;
    casts += current_coins != 0;
    cout << coins << ' ' << casts;
    return 0;
}