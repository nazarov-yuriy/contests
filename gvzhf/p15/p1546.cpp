#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    int ai = 0, bi = 0;
    int az = 0, bz = 0;
    while (ai < a.length() && bi < b.length()) {
        if (a[ai] >= 'a' || b[bi] >= 'a') {
            if (a[ai] != b[bi])
                return a[ai] < b[bi];
            else {
                ai++;
                bi++;
            }
        } else {
            while (ai < a.length() && a[ai] == '0') {
                ai++;
                az++;
            }
            while (bi < b.length() && b[bi] == '0') {
                bi++;
                bz++;
            }
            int ao = ai, bo = bi;
            while (ai < a.length() && a[ai] <= '9') { ai++; }
            while (bi < b.length() && b[bi] <= '9') { bi++; }
            if (ai - ao != bi - bo) return ai - ao < bi - bo;
            for (int i = 0; i < ai - ao; i++) { if (a[ao + i] != b[bo + i]) return a[ao + i] < b[bo + i]; }
        }
    }
    if (ai != a.length() || bi != b.length()) return ai == a.length();
    for (int i = 0; i < min(a.length(), b.length()); i++) {
        if (a[i] != b[i]) return a[i] == '0'; //ToDo
    }
    if (b.length() > a.length() && b[a.length()] == '0'){
        return false;
    }
    if (a.length() > b.length() && a[b.length()] == '0'){
        return true;
    }
    return a.length() < b.length();
}

int main() {
    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        if (line.length() == 0) break;
        lines.push_back(line);
    }
    sort(lines.begin(), lines.end(), cmp);
    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
    return 0;
}
