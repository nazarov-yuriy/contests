#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> used;
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        if (used.count(line)) {
            if (n == 2)
                cout << 0;
            else
                cout << "Impossible";
            return 0;
        } else {
            used.insert(line);
        }
    }
    if (n == 1) {
        cout << 0;
    } else if (n == 2) {
        cout << 1 << endl;
        auto it1 = used.begin();
        auto it2 = used.begin();
        it2++;
        cout << *it1 << '-' << *it2;
    } else {
        string lang = "lsmvzqmxhp";
        cout << n << endl;
        for (auto it = used.begin(); it != used.end(); ++it) {
            cout << lang << '-' << *it << endl;
        }
    }
    return 0;
}