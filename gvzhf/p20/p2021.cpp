#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

struct member {
    int pos;
    int val;
};

bool comparePairs(const member &lhs, const member &rhs) {
    return lhs.val < rhs.val;
}

int main() {
    unsigned int n;
    cin >> n;
    vector<member> first(n);
    vector<member> second(n);
    int f_summ = 0, s_summ = 0;
    for (int i = 0; i < n; i++) {
        cin >> first[i].val;
        f_summ += first[i].val;
        first[i].pos = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> second[i].val;
        s_summ += second[i].val;
        second[i].pos = i;
    }
    sort(first.begin(), first.end(), comparePairs);
    sort(second.begin(), second.end(), comparePairs);
    if (f_summ < s_summ) {
        for (int i = 0; i < n; i++) {
            cout << first[n - 1 - i].pos + 1 /* << "(" << first[n - 1 - i].val << ")"*/ << " ";
            cout << second[i].pos + 1 /* << "(" << second[i].val << ")" */ << endl;
        }
    } else {
        for (int i = 0; i < n; i++) {
            cout << first[i].pos + 1 /*<< "(" << first[i].val << ")" */ << " ";
            cout << second[n - 1 - i].pos + 1 /* << "(" << second[n - 1 - i].val << ")" */ << endl;
        }
    }
    return 0;
}
