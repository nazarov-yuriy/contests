#include <iostream>

using namespace std;

int main() {
    string str;
    int n, skipD = 0, skipR = 0, cntD = 0, cntR = 0;
    cin >> n >> str;
    bool skip[n] = {};
    for (int i = 0; i < str.length(); ++i) {
        if ('D' == str[i]) cntD++; else cntR++;
    }
    while (cntR && cntD) {
        for (int i = 0; i < str.length(); ++i) {
            if(!skip[i]) {
                if ('D' == str[i]) {
                    if (skipD) {
                        skipD--;
                        cntD--;
                        skip[i] = true;
                    } else {
                        skipR++;
                    }
                } else {
                    if (skipR) {
                        skipR--;
                        cntR--;
                        skip[i] = true;
                    } else {
                        skipD++;
                    }
                }
            }
        }
    }
    cout << (cntR ? 'R' : 'D');
    return 0;
}