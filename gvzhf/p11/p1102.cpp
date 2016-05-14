#include <iostream>

using namespace std;

int main() {
    int n;
    ios_base::sync_with_stdio(0);
    cin >> n;
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        bool ok = true;
        getline(cin, line);
        for (int j = line.length() - 1; j >= 0; j--) {
            if (line[j] == 'e') {
                if (j >= 2 && line[j - 1] == 'n' && line[j - 2] == 'o')
                    j -= 2;
                else {
                    ok = false;
                    break;
                }
            } else if (line[j] == 'n') {
                if (j >= 1 && line[j - 1] == 'i') {
                    j--;
                } else if (j >= 4 && line[j - 1] == 'o' && line[j - 2] == 't' && line[j - 3] == 'u' &&
                           line[j - 4] == 'p') {
                    j -= 4;
                } else {
                    ok = false;
                    break;
                }
            } else if (line[j] == 't') {
                if (j >= 2 && line[j - 1] == 'u' && line[j - 2] == 'o') {
                    j -= 2;
                } else if (j >= 4 && line[j - 1] == 'u' && line[j - 2] == 'p' && line[j - 3] == 'n' &&
                           line[j - 4] == 'i') {
                    j -= 2;
                } else if (j >= 5 && line[j - 1] == 'u' && line[j - 2] == 'p' && line[j - 3] == 't' &&
                           line[j - 4] == 'u' && line[j - 5] == 'o') {
                    j -= 2;
                } else {
                    ok = false;
                    break;
                }
            } else {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}