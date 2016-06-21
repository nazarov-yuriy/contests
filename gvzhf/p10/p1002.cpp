#include <iostream>
#include <map>

using namespace std;

string dig(string s) {
    string res = "";
    for (int i = 0; i < s.length(); i++) {
        char c;
        switch (s[i]) {
            case 'i':
            case 'j':
                c = '1';
                break;
            case 'a':
            case 'b':
            case 'c':
                c = '2';
                break;
            case 'd':
            case 'e':
            case 'f':
                c = '3';
                break;
            case 'g':
            case 'h':
                c = '4';
                break;
            case 'k':
            case 'l':
                c = '5';
                break;
            case 'm':
            case 'n':
                c = '6';
                break;
            case 'p':
            case 'r':
            case 's':
                c = '7';
                break;
            case 't':
            case 'u':
            case 'v':
                c = '8';
                break;
            case 'w':
            case 'x':
            case 'y':
                c = '9';
                break;
            case 'o':
            case 'q':
            case 'z':
                c = '0';
                break;
        }
        res += c;
    }
    return res;
}

int main() {
    string number, str;
    getline(cin, number);
    while (number != "-1") {
        int n;
        cin >> n;
        map<string, string> dict;
        for (int i = 0; i < n; i++) {
            cin >> str;
            dict[dig(str)] = str;
        }
        string last[101];
        int len[101] = {};
        for (int i = 1; i <= number.length(); i++) {
            string min_word;
            int min_len = 1000000000;
            for (unsigned int j = 0; j < i; j++) {
                if ((j == 0 || last[j].length()) && dict.count(number.substr(j, i - j))) {
                    if (len[j] + 1 < min_len) {
                        min_len = len[j] + 1;
                        min_word = dict[number.substr(j, i - j)];
                    }
                }
            }
            last[i] = min_word;
            len[i] = min_len;
        }
        if (len[number.length()] != 1000000000) {
            int left = number.length();
            string res = "";
            while (left) {
                res = last[left] + " " + res;
                left -= last[left].length();
            }
            cout << res << endl;
        } else {
            cout << "No solution." << endl;
        }
        getline(cin, number);
        getline(cin, number);
    }
    return 0;
}