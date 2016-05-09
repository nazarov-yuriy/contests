#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    int x = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        if ("X++" == line || "++X" == line) x++;
        if ("X--" == line || "--X" == line) x--;
    }
    cout << x;
    return 0;
}