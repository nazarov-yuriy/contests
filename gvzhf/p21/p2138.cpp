#include <iostream>

using namespace std;

int main() {
    string s;
    unsigned int v;
    cin >> s >> v;
    v = ((v & (0xffu << 0)) << 24) | ((v & (0xffu << 8)) << 8) | ((v & (0xffu << 16)) >> 8) | ((v & (0xffu << 24)) >> 24);
    cout << v << endl;
    return 0;
}