#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    getline(cin, str);
    while (getline(cin, str)) {
        string line;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0' || str[i] == '1') line += str[i];
        }
        if(line.length() == 0) continue;
        int s = 0;
        int ones[n + 2] = {};
        for (int i = line.length() - 1; i >= 0; i--) {
            if (line[i] == '1') {
                s += i + 1;
                ones[i] = 1 + ones[i + 1];
            } else {
                ones[i] = ones[i + 1];
            }
        }
        if (line.length() == n) {
            for (int i = 0; i < n; i++) {
                if ((i + 1) % (n + 1) == s % (n + 1)) {
                    line[i] = '0';
                    break;
                }
            }
            cout << line << endl;
        } else if (line.length() == n + 1) {
            for (int i = 0; i < n + 1; i++) {
                if (line[i] == '0' && (s - ones[i]) % (n + 1) == 0) {
                    line = line.substr(0, i) + line.substr(i + 1, n + 1 - i);
                    break;
                } else if (line[i] == '1' && (s - ones[i] - i) % (n + 1) == 0) {
                    line = line.substr(0, i) + line.substr(i + 1, n + 1 - i);
                    break;
                }
            }
            cout << line << endl;
        } else if (line.length() == n - 1) {
            for (int i = 0; i < n; i++) {
                if ((s + ones[i]) % (n + 1) == 0) {
                    line = line.substr(0, i) + "0" + line.substr(i, n - i - 1);
                    break;
                } else if ((s + ones[i] + i + 1) % (n + 1) == 0) {
                    line = line.substr(0, i) + "1" + line.substr(i, n - i - 1);
                    break;
                }
            }
            cout << line << endl;
        } else {
            return 1;
        }
    }
    return 0;
}