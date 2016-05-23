#include <iostream>

using namespace std;

long long unsigned int cnt0[128][128] = {};
long long unsigned int cnt[129] = {};

unsigned long long int pos_to_val(int pos) {
    return 0b0101010101010101010101010101010101010101010101010101010101010101ULL >> (64 - pos);
}

int val_to_pos(unsigned long long int val) {
    int res = 1;
    char prev = '0';
    for (int i = 62; i >= 0; i--) {
        if (prev == '0') {
            if (val & (1LL << i)) {
                prev = '1';
                res++;
            }
        } else {
            if ((val & (1LL << i)) == 0) {
                prev = '0';
                res++;
            }
        }
    }
    return res;
}

void add(unsigned long long int left, int order) {
    for (int j = 1; j <= 65; j++) {
        cnt[j - 1 + val_to_pos(left - 1)] += cnt0[order][j] + cnt0[order][j - 1];
    }
}

int main() {
    cnt0[0][0] = 1;
    for (int i = 1; i < 128; i++) {
        for (int j = 1; j < 128; j++) {
            cnt0[i][j] = cnt0[i - 1][j] + cnt0[i - 1][j - 1];
        }
    }
    long long unsigned int n;
    cin >> n;
    n++;
    for (int i = 62; i >= 0; i--) {
        if ((1LL << i) & n) {
            add(n >> i, i);
        }
    }
    unsigned long long int res = 0;
    for (int j = 0; j <= 64; j++) {
        res += (cnt[j] % 1000000007) * (pos_to_val(j) % 1000000007);
        res = res % 1000000007;
    }
    cout << res << endl;
    return 0;
}