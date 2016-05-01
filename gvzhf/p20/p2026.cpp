#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    int k = 0;
    cin >> k;
    set<char> types;
    vector<int> imp;
    vector<int> noimp;
    for (int i = 0; i < line.length(); i++) {
        char c = line.c_str()[i];
        if (c == '?' && i % 2 == 0) {
            imp.push_back(i);
        } else if (c == '?' && i % 2 == 1) {
            noimp.push_back(i);
        } else {
            types.insert(c);
        }
    }
    if (k > types.size() + imp.size() + noimp.size()) {
        cout << -1;
    } else {
        if (types.count('z') == 0 && imp.size()) {
            line[imp.back()] = 'z';
            imp.pop_back();
            types.insert('z');
        }
        if (types.count('a') == 0 && noimp.size()) {
            line[noimp.back()] = 'a';
            noimp.pop_back();
            types.insert('a');
        }
        while (k > types.size()) {
            char best_imp = 'z';
            char best_noimp = 'a';
            for (char c = 'a'; c <= 'z'; c++) {
                if (types.count(c) == 0) best_imp = c;
            }
            for (char c = 'z'; c >= 'a'; c--) {
                if (types.count(c) == 0) best_noimp = c;
            }
            if ((best_imp - 'a' > 'z' - best_noimp || noimp.size() == 0) && imp.size()) {
                line[imp.back()] = best_imp;
                imp.pop_back();
                types.insert(best_imp);
            } else {
                line[noimp.back()] = best_noimp;
                noimp.pop_back();
                types.insert(best_noimp);
            }
        }
        for (auto it = imp.begin(); it != imp.end(); ++it) {
            line[*it] = 'z';
        }
        for (auto it = noimp.begin(); it != noimp.end(); ++it) {
            line[*it] = 'a';
        }
        cout << line;
    }
    return 0;
}