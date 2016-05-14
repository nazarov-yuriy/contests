#include <iostream>
#include <cstdio>

using namespace std;

int read_int(char **pointer){
    int res = 0;
    int sign = 1;
    while(**pointer<'0'){
        if(**pointer == '-') sign = -1;
        (*pointer)++;
    }
    while(**pointer>='0'){
        res *= 10;
        res += **pointer-'0';
        (*pointer)++;
    }
    return res*sign;
}

int main() {
    int n = 1000000;
    int *coins = new int[2*n];
    char *buf_out = new char[10*n];
    char *pointer_out = buf_out;
    char *buf_in = new char[11*n+11];
    buf_out[0] = 0;
    int top = n;
    int bottom = n;
    fread(buf_in, 11*n+11, 1, stdin);
    n = read_int(&buf_in);
    for (int i = 0; i < n; i++) {
        int t;
        t = read_int(&buf_in);
        if (t == 0) {
            int l = top - bottom;
            for (int j = 0; bottom > 0 && j < l; j++) {
                coins[--bottom] = coins[top - 1 - j];
            }
        } else if(t > 0){
            coins[top++] = t;
        } else {
            pointer_out += sprintf(pointer_out, "%d\n", coins[--top]);
        }
    }
    puts(buf_out);
    return 0;
}