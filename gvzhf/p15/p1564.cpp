#include <iostream>

using namespace std;

long long int ones(long long int v) {
    long long res = 0;
    while (v) {
        if (v % 10 == 1) res++;
        v /= 10;
    }
    return res;
}

long long int cache[20] = {
        0,
        1,
        20,
        300,
        4000,
        50000,
        600000,
        7000000,
        80000000,
        900000000,
        10000000000LL,
        110000000000LL,
        1200000000000LL,
        13000000000000LL,
        140000000000000LL,
        1500000000000000LL,
        16000000000000000LL,
        170000000000000000LL,
        1800000000000000000LL,
};

long long int p10[] = {
        1LL,
        10LL,
        100LL,
        1000LL,
        10000LL,
        100000LL,
        1000000LL,
        10000000LL,
        100000000LL,
        1000000000LL,
        10000000000LL,
        100000000000LL,
        1000000000000LL,
        10000000000000LL,
        100000000000000LL,
        1000000000000000LL,
        10000000000000000LL,
        100000000000000000LL,
        1000000000000000000LL,
};

long long int oc(long long starts, int chars) {
    starts--;
    long long res = 0;
    /*for (int i = 0; i < p10[chars]; i++) {
        res += ones(i);
    }*/
    res += cache[chars];
    return res + p10[chars] * ones(starts);
}

long long int fast(long long v) {
    long long res = 0;
    int chars = 0;
    while (v) {
        for (; v % 10; v--) {
            res += oc(v, chars);
        }
        v = v / 10;
        chars++;
    }
    return res;
}

int main() {
    long long int n, res = 0, one_c;
    cin >> n;
    for(long long int it = 1LL<<60;it>0;it/=2){
        if(fast(res+it)<=n){
            res += it;
        }
    }
    one_c = fast(res);
    while(fast(res-1) == one_c){
        res--;
    }
    if(fast(res) == n){
        cout << res-1;
    }else{
        cout << "Petr lies";
    }
    return 0;
}
