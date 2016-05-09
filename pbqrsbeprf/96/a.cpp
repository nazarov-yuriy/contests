#include <iostream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    int run[2] = {};
    char last = line[0];
    for (int i = 0; i < line.length(); i++) {
        if (last == line[i]) {
            run[last - '0']++;
            if (run[last - '0'] >= 7) {
                cout << "YES";
                return 0;
            }
        } else {
            run[last - '0'] = 0;
            run['1' - last] = 1;
        }
        last = line[i];
    }
    cout << "NO";
    return 0;
}