#include <iostream>

using namespace std;

string str;
int n;
short int cache[4002] = {};
char pal[4002][4002] = {};
int res[4002];

int best(int from) {
    if (from >= n) return 0;
    if (cache[from]) return cache[from];
    int m = 32767, mi = 0;
    for (int i = from; i < n; i++) {
        if (pal[from][i]) {
            if (m > best(i + 1) + 1) {
                m = best(i + 1) + 1;
                mi = i;
            }
        }
    }
    res[from] = mi;
    return cache[from] = m;
}

int main() {
    cin >> str;
    n = str.length();
    for (int i = 0; i < n; i++) {
        pal[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        pal[i][i + 1] = str[i] == str[i + 1];
    }
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            int f = j;
            int t = j + i;
            pal[f][t] = (str[f] == str[t]) && pal[f + 1][t - 1];
        }
    }
    cout << best(0) << endl;
    int pos = 0;
    while (pos < n) {
        cout << str.substr(pos, res[pos] - pos + 1) << ' ';
        pos = res[pos] + 1;
    }
    return 0;
}
/*
{
 {1 2 1 2 1}
 {0 1 2 1 2}
 {0 0 1 2 1}
 {0 0 0 1 2}
 {0 0 0 0 1}
}
 */