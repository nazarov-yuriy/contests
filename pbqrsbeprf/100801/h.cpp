#include <iostream>
#include <fstream>

using namespace std;

static inline int jhash(char a, char b, char c, char d, char e, char f, char g, char h, char i, char j, char k) {
    int res = a;
    res = (res << 4) + (res << 3) + (res << 2) + (res << 1) + res + b;
    res = (res << 4) + (res << 3) + (res << 2) + (res << 1) + res + c;
    res = (res << 4) + (res << 3) + (res << 2) + (res << 1) + res + d;
    res = (res << 4) + (res << 3) + (res << 2) + (res << 1) + res + e;
    res = (res << 4) + (res << 3) + (res << 2) + (res << 1) + res + f;
    res = (res << 4) + (res << 3) + (res << 2) + (res << 1) + res + g;
    res = (res << 4) + (res << 3) + (res << 2) + (res << 1) + res + h;
    res = (res << 4) + (res << 3) + (res << 2) + (res << 1) + res + i;
    res = (res << 4) + (res << 3) + (res << 2) + (res << 1) + res + j;
    res = (res << 4) + (res << 3) + (res << 2) + (res << 1) + res + k;
    return res;
}

int main() {
    int n;
    ifstream inFile("hash.in");
    ofstream outFile("hash.out");
    inFile >> n;
    for (int it = 0; it < n; it++) {
        int k = it & 0b00000000001 ? 31 : 0;
        int j = it & 0b00000000010 ? 31 : 0;
        if (k < 31) j++;
        int i = it & 0b00000000100 ? 31 : 0;
        if (j < 31) i++;
        int h = it & 0b00000001000 ? 31 : 0;
        if (i < 31) h++;
        int g = it & 0b00000010000 ? 31 : 0;
        if (h < 31) g++;
        int f = it & 0b00000100000 ? 31 : 0;
        if (g < 31) f++;
        int e = it & 0b00001000000 ? 31 : 0;
        if (f < 31) e++;
        int d = it & 0b00010000000 ? 31 : 0;
        if (e < 31) d++;
        int c = it & 0b00100000000 ? 31 : 0;
        if (d < 31) c++;
        int b = it & 0b01000000000 ? 31 : 0;
        if (c < 31) b++;
        int a = it & 0b10000000000 ? 31 : 0;
        if (b < 31) a++;
        a += 'H';
        b += 'H';
        c += 'H';
        d += 'H';
        e += 'H';
        f += 'H';
        g += 'H';
        h += 'H';
        i += 'H';
        j += 'H';
        k += 'H';
        outFile << (char) a << (char) b << (char) c << (char) d << (char) e << (char) f << (char) g << (char) h << (char) i << (char) j << (char) k;
        outFile << /*' ' << jhash(a, b, c, d, e, f, g, h, i, j, k) <<*/ endl;
    }
    return 0;
}