#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    int n, id = 0;
    cin >> n;
    unordered_map<string, int> ids;
    int langs[1001];
    ids["unknown"] = id++;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (!ids.count(str)) ids[str] = id++;
        langs[i] = ids[str];
    }
    int answers = 0;
    for (int i = 1; i <= n; i++) {
        if (0 == n % i) {
            set<int> used;
            bool ok = true;
            for (int j = 0; j < i; j++) {
                int lang = 0;
                for (int k = 0; k < n / i; k++) {
                    if (langs[k + j * n / i]) {
                        if (lang && lang != langs[k + j * n / i]) {
                            ok = false;
                            break;
                        } else {
                            lang = langs[k + j * n / i];
                        }
                    }
                }
                if (lang && used.count(lang)) {
                    ok = false;
                } else {
                    used.insert(lang);
                }
                if (!ok) break;
            }
            if (ok) {
                answers++;
                cout << i << ' ';
            }
        }
    }
    if (!answers) cout << "Igor is wrong.";
    return 0;
}