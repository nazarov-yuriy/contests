#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    ios_base::sync_with_stdio(0);
    cin >> n;
    string t;
    getline(cin, t);
    for (int i = 0; i < n; i++) {
        list<char> pass;
        //char left[1000000], right[1000000], lp = 0, rp = 0;
        auto it = pass.begin();
        string s;
        getline(cin, s);
        for (int j = 0; j < s.length(); j++) {
            char c = s[j];
            if (c == '<') {
                if (it != pass.begin()) --it;
            } else if (c == '>') {
                if (it != pass.end()) ++it;
            } else if (c == '-') {
                if (it != pass.begin()) it = pass.erase(--it);
            } else {
                pass.insert(it, c);
            }
        }
        s.resize(pass.size());
        int j = 0;
        for (auto jt = pass.begin(); jt != pass.end(); ++jt) {
            s[j++] = *jt;
        }
        cout << s << '\n';
    }
    return 0;
}