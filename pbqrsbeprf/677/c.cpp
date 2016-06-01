#include <iostream>

using namespace std;

unsigned long long int get_zeroes(char c) {
    int code;
    if ('0' <= c && c <= '9') {
        code = c - '0';
    }
    if ('A' <= c && c <= 'Z') {
        code = c - 'A' + 10;
    }
    if ('a' <= c && c <= 'z') {
        code = c - 'a' + 36;
    }
    if (c == '-') code = 62;
    if (c == '_') code = 63;
    unsigned long long int res = 1;
    for (int i = 0; i < 6; i++) {
        if (0 == (code & (1 << i)))
            res*=3;
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    unsigned long long int res = 1;
    for (int i = 0; i < str.length(); i++) {
        res *= get_zeroes(str[i]);
        res = res % 1000000007;
    }
    cout << res;
    return 0;
}