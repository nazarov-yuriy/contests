#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct poly {
    unsigned int coef[26];
    int sum;
    long long int mult;
};

poly mult(poly a, poly b) {
    for (int i = 0; i < 26; i++) {
        a.coef[i] += b.coef[i];
    }
    a.sum += b.sum;
    a.mult *= b.mult;
    return a;
}

poly add(poly a, poly b) {
    a.mult += b.mult;
    return a;
}

poly parse(string sign, string p) {
    int t;
    poly res = {};
    res.mult = sign == "-" ? -1 : 1;
    stringstream ss(p);
    string item;
    while (getline(ss, item, '*')) {
        if ('a' <= item[0]) {
            if (item[1] == '^') {
                stringstream d(item.substr(2));
                d >> t;
                res.coef[item[0] - 'a'] += t;
                res.sum += t;
            } else {
                res.coef[item[0] - 'a']++;
                res.sum++;
            }
        } else {
            stringstream d(item);
            d >> t;
            res.mult *= t;
        }
    }
    return res;
}

bool cmp(poly a, poly b) {
    if (a.sum < b.sum) return false;
    if (a.sum > b.sum) return true;
    for (int i = 0; i < 26; i++) {
        if (a.coef[i] < b.coef[i]) return false;
        if (a.coef[i] > b.coef[i]) return true;
    }
    return false;
}

bool eq(poly a, poly b) {
    for (int i = 0; i < 26; i++) if (a.coef[i] != b.coef[i]) return false;
    return true;
}

bool first = true;

void print(poly cur) {
    bool m = false;
    if (cur.mult != 0) {
        if (first) {
            if (abs(cur.mult) != 1 || !cur.sum) {
                cout << cur.mult;
                m = true;
            } else if (cur.mult == -1) {
                cout << "-";
            }
        } else {
            cout << (cur.mult < 0 ? " - " : " + ");
            if (abs(cur.mult) != 1 || !cur.sum) {
                cout << abs(cur.mult);
                m = true;
            }
        }

        first = false;
        for (int i = 0; i < 26; i++) {
            if (cur.coef[i]) {
                cout << (m ? "*" : "") << (char) ('a' + i);
                if (cur.coef[i] != 1) cout << '^' << (int) cur.coef[i];
                m = true;
            }
        }
    }
}

int main() {
    string a, b, sign = "+", p = "";
    getline(cin, a);
    getline(cin, b);
    vector<poly> ina, inb, out;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '+' || a[i] == '-') {
            if (p != "") ina.push_back(parse(sign, p));
            sign = a[i];
            p = "";
        } else {
            if (a[i] != ' ') p += a[i];
        }
    }
    if (p != "") ina.push_back(parse(sign, p));
    sign = "+";
    p = "";
    for (int i = 0; i < b.length(); i++) {
        if (b[i] == '+' || b[i] == '-') {
            if (p != "") inb.push_back(parse(sign, p));
            sign = b[i];
            p = "";
        } else {
            if (b[i] != ' ') p += b[i];
        }
    }
    if (p != "") inb.push_back(parse(sign, p));

    for (auto ita = ina.begin(); ita != ina.end(); ita++) {
        for (auto itb = inb.begin(); itb != inb.end(); itb++) {
            out.push_back(mult(*ita, *itb));
        }
    }

    if (!out.empty()) {
        sort(out.begin(), out.end(), cmp);
        poly cur = *out.begin();
        for (auto it = out.begin() + 1; it != out.end(); ++it) {
            if (eq(cur, *it)) {
                cur = add(cur, *it);
            } else {
                print(cur);
                cur = *it;
            }
        }
        print(cur);
    }
    if (first)
        cout << "0";
    return 0;
}