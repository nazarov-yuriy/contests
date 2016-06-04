#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dif[10];

int worst(int *prize) {
    int worst0 = min(
            min(prize[0] + dif[0], prize[1] + dif[1]),
            min(prize[2] + dif[2], prize[3] + dif[3])
    );
    int worst1 = min(
            min(prize[4] + dif[4], prize[5] + dif[5]),
            min(prize[6] + dif[6], prize[7] + dif[7])
    );
    int worst2 = min(prize[8] + dif[8], prize[9] + dif[9]);
    return min(min(worst0, worst1), worst2);
}

int main() {
    int max_p[] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> in;
    for (int i = 0; i < 10; i++) {
        int t;
        cin >> t;
        in.push_back(t);
    }
    sort(in.begin(), in.end(), less<int>());
    for (int i = 0; i < 10; i++) {
        dif[i] = in[i];
    }
    int prize[11];
    for (int i = 30; i >= 0; i--) {
        int pos = 0;
        for (int j = 0; j < 11; j++) {
            if (i != j) prize[pos++] = max_p[j];
        }
        int w = worst(prize);
        if (max_p[i] > w) {
            if (i == 30) {
                cout << 1000;
                return 0;
            } else {
                cout << i + 1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}