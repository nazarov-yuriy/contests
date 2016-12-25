#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main() {
    string definition, argName, tmp;
    int newPos;
    getline(cin, definition);
    cin >> argName >> newPos;
    stringstream ssd(definition);
    getline(ssd, tmp, '(');
    getline(ssd, tmp, ')');
    string args = tmp;
    stringstream ssa(args);
    map<char, int> positions;
    int pos = 0;
    while (std::getline(ssa, tmp, ',')) {
        positions[tmp[tmp.length() - 1]] = ++pos;
    }
    int oldPos = positions[argName[0]];
    if (oldPos != newPos) {
        if ((oldPos == 1 && newPos == positions.size()) ||
            (newPos == 1 && oldPos == positions.size())) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}