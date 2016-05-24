#include <iostream>

using namespace std;

string repl_(string s) {
    string res = s;
    for (int i = 0; i < s.size(); i++) {
        res[i] = s[i] == ' ' ? ' ' : '_';
    }
    return res;
}

int main() {
    string actual, word, res;
    size_t from = 0;
    getline(cin, actual);
    while (getline(cin, word, ' ')) {
        if (word == "" || word == "\n") break;//continue;
        if (word[word.size() - 1] == '\n') word = word.substr(0, word.size() - 1);
        size_t pos = actual.find(word, from ? from + 1 : 0);
        if (pos == string::npos) {
            cout << "I HAVE FAILED!!!";
            return 0;
        } else {
            res += repl_(actual.substr(from, pos-from));
            res += word;
            from = pos+word.size();
        }
    }
    res += repl_(actual.substr(from));
    cout << res;
    return 0;
}