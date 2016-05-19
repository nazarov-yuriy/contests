#include <iostream>

using namespace std;

void print_n(string str, int n) {
    for (int i = 0; i < n; i += 3) {
        if (i + 3 > n) {
            cout << str.substr(0, n - i);
        } else {
            cout << str;
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    if (n * 6 > 100000) {
        cout << "TOO LONG";
    } else if (n == 1) {
        cout << "a" << endl;
        cout << "b" << endl;
        cout << "c" << endl;
    } else {
        print_n("abc", n);
        print_n("acb", n);
        print_n("bac", n);
        print_n("bca", n);
        print_n("cab", n);
        print_n("cba", n);
    }
    return 0;
}