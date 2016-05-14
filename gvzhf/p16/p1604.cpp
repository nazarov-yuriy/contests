#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct val_cnt {
    int cnt;
    int val;
};

bool cmp(val_cnt a, val_cnt b) {
    return a.cnt > b.cnt;
}

int main() {
    int n;
    cin >> n;
    list <val_cnt> signs;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t) signs.push_back({t, i});
    }
    signs.sort(cmp);
    while (signs.size()) {
        auto first = signs.begin();
        cout << first->val + 1 << ' ';
        first->cnt--;
        if (signs.size() > 1) {
            auto second = signs.begin();
            second++;
            cout << second->val + 1 << ' ';
            second->cnt--;
            if (second->cnt == 0) {
                signs.erase(second);
            } else if (signs.size() > 2) {
                auto third = signs.begin();
                third++;
                third++;
                if (third->cnt > second->cnt) {
                    for (auto it = third; ; ++it) {
                        if (it == signs.end() || it->cnt <= second->cnt) {
                            signs.insert(it, *second);
                            signs.erase(second);
                            break;
                        }
                    }
                }
            }
        }
        if (first->cnt == 0) {
            signs.erase(first);
        } else if (signs.size() > 1) {
            auto second = signs.begin();
            second++;
            if (second->cnt > first->cnt) {
                for (auto it = second; ; ++it) {
                    if (it == signs.end() || it->cnt <= first->cnt) {
                        signs.insert(it, *first);
                        signs.erase(first);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}