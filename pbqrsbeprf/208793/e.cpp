#include <iostream>

using namespace std;

int main() {
    int n, zeroes = 0;
    string str;
    cin >> n >> str;
    for (int i = 0; i < str.length(); i++) {
        if ('0' == str[i]) zeroes++;
    }
    cout << abs(n - zeroes - zeroes);
    return 0;
}