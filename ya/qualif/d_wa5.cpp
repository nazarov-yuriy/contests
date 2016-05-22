#include <iostream>

using namespace std;

long long unsigned int cnt0[64][64] = {};
long long unsigned int cnt1[64][64] = {};
long long unsigned int cnt[128] = {};

string pos_to_mask0(int pos) {
    return ((string) "0101010101010101010101010101010101010101010101010101010101010101").substr(0, pos % 64);
}

string pos_to_mask1(int pos) {
    return ((string) "1010101010101010101010101010101010101010101010101010101010101010").substr(0, pos % 64);
}

unsigned long long int pos_to_val(int pos){
    return 0b0101010101010101010101010101010101010101010101010101010101010101ULL >> (64-pos);
}

int main() {
    cnt0[0][1] = 1;
    cnt1[0][1] = 1;
    for (int i = 1; i < 64; i++) {
        for (int j = 1; j < 64; j++) {
            cnt0[i][j] = cnt0[i - 1][j] + cnt1[i - 1][j - 1];
            cnt1[i][j] = cnt1[i - 1][j] + cnt0[i - 1][j - 1];
        }
    }
/*    for (int i = 0; i < 64; i++) {
        cout << i << ": " << endl;
        for (int j = 0; j < 64; j++) {
            if (cnt0[i][j]) cout << pos_to_mask0(j) << ":" << cnt0[i][j] << " ";
            if (cnt1[i][j]) cout << pos_to_mask1(j) << ":" << cnt1[i][j] << " ";
        }
        cout << endl;
    }*/
    long long unsigned int n;
    cin >> n;
    n++;
    int shift = 1;
    for (int i = 62; i > 0; i--) {
        if ((1LL << i) & n) {
            for (int j = 1; j < 64; j++) {
                int o = 1 - shift&1;
                int z = shift&1;
                cnt[j+shift-1] += cnt0[i - 1][j - o] + cnt1[i - 1][j - z];
            }
            if (shift & 1) shift++;
        } else {
            if ((shift & 1) == 0) shift++;
        }
    }
    if (n&1){
        cnt[++shift]++;
    }
    unsigned long long int res = 0;
    for (int j = 0; j < 64; j++) {
        res += cnt[j]*pos_to_val(j);
        //if (cnt[j]) cout << pos_to_mask0(j) << ":" << cnt[j] << " ";
    }
    cout << res;
    return 0;
}