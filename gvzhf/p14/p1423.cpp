#include <iostream>
#include <map>

using namespace std;

#define L 8

uint64_t roll(uint64_t old, char to_add, char to_remove) {
    old -= 101LL * 101LL * 101LL * 101LL * 101LL * 101LL * 101LL * ((unsigned char) to_remove);
    old *= 101LL;
    return old + ((unsigned char) to_add);
}

int main() {
    int n;
    string s, t;
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    getline(cin, t);
    if (n < 1000) {
        for (int si = 0; si < n; si++) {
            bool match = true;
            for (int st = 0; st < n; st++) {
                if (s[(si + st) % n] != t[st % n]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << (n - si) % n << endl;
                return 0;
            }
        }
        cout << -1 << endl;
        return 0;
    }
    uint64_t shash = 0, thash = 0;
    for (int i = n - L; i < n; i++) {
        shash = roll(shash, s[i], 0);
        thash = roll(thash, t[i], 0);
    }
    map<uint64_t, int> cnt;
    map<uint64_t, int> pos;
    for (int i = 0; i < n; i++) {
        shash = roll(shash, s[i % n], s[(i + n - L) % n]);
        cnt[shash]++;
        pos[shash] = i;
    }
    int min_cnt = 1000000, min_pos = 0;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        if (min_cnt > it->second) {
            min_cnt = it->second;
            shash = it->first;
            min_pos = pos[shash];
        }
    }

    for (int i = 0; i < n; i++) {
        thash = roll(thash, t[i % n], t[(i + n - L) % n]);
        if (thash == shash) {
            int diff = (2*n + i - min_pos) % n;
            bool match = true;
            for (int j = 0; j < n; j++) {
                if (s[j] != t[(j + diff) % n]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << diff;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}