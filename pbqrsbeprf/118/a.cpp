#include <iostream>

using namespace std;

int main() {
    int chr = getchar();
    while ('A' <= chr && chr <= 'z') {
        chr = tolower(chr);
        switch (chr) {
            case 'a':
            case 'o':
            case 'y':
            case 'e':
            case 'u':
            case 'i':
                break;
            default:
                cout << '.' << (char) chr;
        }
        chr = getchar();
    }
    return 0;
}