#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int s1, r1, s2, r2, ds, dr;
    long long int mins = 1000000000, minr = 1000000000, maxs = -1000000000, maxr = -1000000000;
    long long int minsn = 0, minrn = 0, maxsn = 0, maxrn = 0;

    cin >> s1 >> r1 >> s2 >> r2;
    mins = min(s1, mins);
    if (mins == s1) minsn = 1;
    minr = min(r1, minr);
    if (minr == r1) minrn = 1;
    maxs = max(s1, maxs);
    if (maxs == s1) maxsn = 1;
    maxr = max(r1, maxr);
    if (maxr == r1) maxrn = 1;

    mins = min(s2, mins);
    if (mins == s2) minsn = 2;
    minr = min(r2, minr);
    if (minr == r2) minrn = 2;
    maxs = max(s2, maxs);
    if (maxs == s2) maxsn = 2;
    maxr = max(r2, maxr);
    if (maxr == r2) maxrn = 2;

    ds = s2 - s1;
    dr = r2 - r1;
    bool in_line = true;
    for (int i = 2; i < n; i++) {
        long long int s, r;
        cin >> s >> r;
        mins = min(s, mins);
        if (mins == s) minsn = i + 1;
        minr = min(r, minr);
        if (minr == r) minrn = i + 1;
        maxs = max(s, maxs);
        if (maxs == s) maxsn = i + 1;
        maxr = max(r, maxr);
        if (maxr == r) maxrn = i + 1;
        if (ds * (r - r1) != dr * (s - s1)) in_line = false;
    }
    if (in_line) {
        cout << 1 << endl;
        if (mins != maxs) {
            cout << minsn << " " << maxsn;
        } else {
            cout << minrn << " " << maxrn;
        }
    } else {
        cout << 0;
    }
    return 0;
}