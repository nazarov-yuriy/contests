#include <iostream>

using namespace std;

void add(int *tree, int n, int to, int val) {
    while (n > 0) {
        if (to % 2) {
            tree[n + to - 1] += val;
            to--;
        }
        to = (to + 1) / 2;
        n /= 2;
    }
}

int val(int *tree, int index) {
    int res = 0;
    while (index) {
        res += tree[index];
        index /= 2;
    }
    return res;
}

int main() {
    int on, bn = 1;
    cin >> on;
    while (bn < on) {
        bn *= 2;
    }
    int tree[2 * bn] = {};
    for (int i = 0; i <= on; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(tree, bn, b, c);
        add(tree, bn, a - 1, -c);
    }
    for (int i = 0; i < on; i++) {
        cout << val(tree, bn + i) << ' ';
    }
    return 0;
}