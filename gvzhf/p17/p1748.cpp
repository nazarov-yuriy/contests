#include <iostream>

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
struct rpair {
    int cnt;
    long long int val;
};

rpair divisors(int pos, int pcnt, long long int m) {
    rpair res = {1, 1};
    int cnt = 2;
    long long int mult = primes[pos];
    while (m >= primes[pos] && cnt <= pcnt) {
        m /= primes[pos];
        if (m >= primes[pos + 1]) {
            rpair next = divisors(pos + 1, cnt, m);
            if (cnt * next.cnt >= res.cnt) {
                res.cnt = cnt * next.cnt;
                res.val = mult * next.val;
            }
        } else {
            if (cnt > res.cnt) {
                res.cnt = cnt;
                res.val = mult;
            }
        }
        cnt++;
        mult *= primes[pos];
    }
    return res;
}

int main() {
    long long int n = 1000000000000000000ll, cnt;
    cin >> cnt;
    for (int j = 0; j < cnt; j++) {
        cin >> n;
        rpair c, l = divisors(0, 50, n);
        do {
            c = l;
            l = divisors(0, 50, c.val - 1);
        } while (l.cnt > 1 && l.cnt == c.cnt);
        cout << c.val << ' ' << c.cnt << endl;
        n--;
    }
    return 0;
}