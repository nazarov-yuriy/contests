#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    long double res = 0;
    string s;
    cin >> s;
    int lp = 0, rp = s.length() - 1;
    while (1) {
        while (lp < rp && s[lp] == '0') {
            lp++;
        }
        while (lp < rp && s[rp] == '1') {
            rp--;
        }
        if (lp >= rp) break;
        res += sqrt(rp - lp);
        lp++;
        rp--;
    }
    cout << setprecision(20) << res;
    return 0;
}