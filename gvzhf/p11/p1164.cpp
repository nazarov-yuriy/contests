#include <iostream>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    int c[26] = {};
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            c[str[j]-'A']++;
        }
    }
    for(int i = 0; i < p; i++){
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            c[str[j]-'A']--;
        }
    }
    for(char ch = 'A'; ch <= 'Z'; ch++){
        for(int i = 0; i < c[ch-'A']; i++){
            cout << ch;
        }
    }
    return 0;
}