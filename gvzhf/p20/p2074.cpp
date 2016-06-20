#include <iostream>
#include <sstream>
#include <set>
#include <map>

using namespace std;

string base(string s) {
    unsigned long int l = (s.length() > 2 && s[s.length() - 3] != '.') ? (s.length() - 3) : (s.length() - 2);
    string res = s.substr(0, l);
    return res;
}

int main() {
    map<int, set<string>> cats;
    map<string, string> res1, res2;
    string line, last_code[22] = {}, last_name[22] = {};
    int pos = 1;
    last_code[pos] = "0.";
    while (std::getline(std::cin, line)) {
        if (line == "") break;
        stringstream s(line);
        if (line[0] != '.' && line[1] != '.' && line[2] != '.') {
            int t;
            s >> t;
            while (t) {
                cats[t].insert(last_name[pos]);
                t = 0;
                s >> t;
            }
        } else {
            string code, n, name;
            s >> code;
            s >> name;
            getline(s, n);
            name += n;
            if (base(code) == last_code[pos]) {
                pos++;
            } else {
                while (base(code) != base(last_code[pos])) {
                    pos--;
                }
            }
            last_code[pos] = code;
            last_name[pos] = last_name[pos - 1] == "" ? name : last_name[pos - 1] + "." + name;
        }
    }
    for (auto it = cats.begin(); it != cats.end(); ++it) {
        auto jt = it->second.begin();
        string s = *jt;
        jt++;
        for (; jt != it->second.end(); ++jt) {
            s += ", " + *jt;
        }
        if (!res1.count(s)) {
            res1[s] = to_string(it->first);
        } else {
            res1[s] += ", " + to_string(it->first);
        }
    }
    for (auto it = res1.begin(); it != res1.end(); ++it) {
        res2[it->second] = it->first;
    }
    for (auto it = res2.begin(); it != res2.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
    return 0;
}