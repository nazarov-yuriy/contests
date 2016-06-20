#include <iostream>

using namespace std;

int main() {
    int res = 0, cnt[] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};
    while (1) {
        int c = getchar();
        if (c == EOF || c == '\n') break;
        res += cnt[c - '0'];
    }
    cout << res;
    return 0;
}