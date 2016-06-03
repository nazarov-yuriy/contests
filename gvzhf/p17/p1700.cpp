#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    map<string, set<string>> inp;
    string str;
    getline(cin, str);
    for (int i = 0; i < n; i++) {
        string name;
        getline(cin, str);
        istringstream iss(str);
        iss >> name;
        name = name.substr(0, name.length() - 1);
        while (iss >> str) {
            inp[name].insert(str);
        }
    }
    cin >> m;
    getline(cin, str);
    for (int i = 0; i < m; i++) {
        getline(cin, str);
        istringstream iss(str);
        string first;
        iss >> first;
        set<string> common = inp[first];
        while (iss >> str) {
            for (auto it = common.begin(); it != common.end();) {
                if (inp[str].count(*it)) {
                    ++it;
                } else {
                    it = common.erase(it);
                }
            }
        }
        if (common.size()) {
            for (auto it = common.begin(); it != common.end(); ++it) {
                cout << *it << ' ';
            }
            cout << endl;
        } else {
            cout << "No solution." << endl;
        }
    }
    return 0;
}