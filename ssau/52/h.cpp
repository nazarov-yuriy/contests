#include <iostream>
#include <vector>

using namespace std;

int main() {
    string tmp, str;
    cin >> tmp;
    unsigned int len = 0;
    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] == '(' || tmp[i] == ')' || tmp[i] == '?') len++;
    }
    str.resize(len);
    len = 0;
    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] == '(' || tmp[i] == ')' || tmp[i] == '?') str[len++] = tmp[i];
    }
    if (str.length() % 2) {
        cout << "Impossible";
        return 0;
    }
    vector<int> left;
    bool keep_run = true;
    while (keep_run) {
        int deep_fwd = 0, deep_bwd = 0;
        vector<int> stack_fwd, stack_bwd;
        keep_run = false;
        for (int i = 0; i < str.length(); i++) {
            if ('(' == str[i]) {
                deep_fwd++;
            }
            if (')' == str[i]) {
                deep_fwd--;
                if (deep_fwd < 0) {
                    if (stack_fwd.size()) {
                        int last = stack_fwd.back();
                        stack_fwd.pop_back();
                        str[last] = '(';
                        keep_run = true;
                        deep_fwd++;
                    } else {
                        cout << "Impossible";
                        return 0;
                    }
                }
            }
            if ('?' == str[i]) {
                stack_fwd.push_back(i);
            }
        }
        for (int i = str.length() - 1; i >= 0; i--) {
            if (')' == str[i]) {
                deep_bwd++;
            }
            if ('(' == str[i]) {
                deep_bwd--;
                if (deep_bwd < 0) {
                    if (stack_bwd.size()) {
                        int last = stack_bwd.back();
                        stack_bwd.pop_back();
                        str[last] = ')';
                        keep_run = true;
                        deep_bwd++;
                    } else {
                        cout << "Impossible";
                        return 0;
                    }
                }
            }
            if ('?' == str[i]) {
                stack_bwd.push_back(i);
            }
        }
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '?') left.push_back(i);
    }
    if (left.size() % 2) {
        cout << "Impossible";
        return 0;
    } else {
        int l = 0, r = left.size() - 1;
        while (l < r) {
            str[left[l]] = '(';
            str[left[r]] = ')';
            l++;
            r--;
        }
        cout << str;
    }
    return 0;
}