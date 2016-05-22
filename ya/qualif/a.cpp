#include <iostream>
#include <vector>

using namespace std;

int diff(string &a, string &b) {
    int res = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) res++;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> words;
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        words.push_back(line);
    }
    for (int i = 0; i < n; i++) {
        int max_dif = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                max_dif = max(max_dif, diff(words[i], words[j]));
            }
        }
        if (max_dif <= 1) {
            cout << words[i] << endl;
            return 0;
        }
    }
    return 0;
}