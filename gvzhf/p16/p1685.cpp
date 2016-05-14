#include <iostream>

using namespace std;


void rec(const char *str, char *res, int f, int t) {
    static int i = 0;
    if (str[i] == 0) exit(1);
    res[(f + t - 1) / 2] = str[i++];
    //cout << str[(f + t - 1) / 2];
    if (t - f > 2) {
        rec(str, res, f, (f + t - 1) / 2);
    }
    if (t - f > 1) {
        rec(str, res, (f + t - 1) / 2 + 1, t);
    }
}

int main() {
    string str;
    getline(cin, str);
    if (str[str.length() - 1] == '\r' || str[str.length() - 1] == '\n')
        str = str.substr(0, str.length() - 1);
    char res[str.length() + 1] = {0};
    rec(str.c_str(), res, 0, str.length());
    cout << res << endl;
    return 0;
}