#include <iostream>

using namespace std;

string forward(string s) {
    string res = "";
    res += s[3];
    res += s[0];
    res += s[2];
    res += s[1];
    return res;
}

string left(string s) {
    string res = "";
    res += s[1];
    res += s[2];
    res += s[0];
    res += s[3];
    return res;
}

string right(string s) {
    string res = "";
    res += s[2];
    res += s[1];
    res += s[3];
    res += s[0];
    return res;
}

string rotate(string s) {
    string res = "";
    res += s[0];
    res += s[2];
    res += s[3];
    res += s[1];
    return res;
}

int main() {
    string first, second;
    cin >> first >> second;
    string f = forward(first), l = left(first), r = right(first);
    if (second == first || second == rotate(first) || second == rotate(rotate(first))) {
        cout << "equal";
    } else if (second == f || second == rotate(f) || second == rotate(rotate(f))) {
        cout << "equal";
    } else if (second == l || second == rotate(l) || second == rotate(rotate(l))) {
        cout << "equal";
    } else if (second == r || second == rotate(r) || second == rotate(rotate(r))) {
        cout << "equal";
    } else {
        cout << "different";
    }
    return 0;
}