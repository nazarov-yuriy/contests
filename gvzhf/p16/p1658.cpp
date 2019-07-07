#include <iostream>

using namespace std;

#define MAX_D 9
#define CNT_D 100
#define MAX_SUM MAX_D * CNT_D
#define MAX_SQUARES_SUM MAX_D * MAX_D * CNT_D

int main() {
    char prev[MAX_SUM+1][MAX_SQUARES_SUM+1] = {};
    char len[MAX_SUM+1][MAX_SQUARES_SUM+1] = {};
    prev[0][0] = -1;

    for (int s = 1; s <= MAX_SUM; s++) {
        for (int i = 1; i <= MAX_D; i++) {
        int smi = s - i;
            if (smi >= 0) {
                for (int j = 0; j <= MAX_SQUARES_SUM; j++) {
                    if (prev[smi][j] && ((0 == len[s][j + i * i]) || len[smi][j] + 1 < len[s][j + i * i])) {
                        prev[s][j + i * i] = i;
                        len[s][j + i * i] = min(len[smi][j] + 1, 120);
                    }
                }
            }
        }
    }
//    for (int i = 0; i < 30; i++) {
//        for (int j = 0; j < 50; j++) {
//            cout << (int)prev[i][j] << ':' << (int)len[i][j] << ' ';
//        }
//        cout << endl;
//    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int sum, squares_sum;
        cin >> sum >> squares_sum;
        if (sum > MAX_SUM || squares_sum > MAX_SQUARES_SUM || !prev[sum][squares_sum]) {
            cout << "No solution" << endl;
        } else {
            int to_out[1000] = {};
            int pos = 0;
            while (sum && pos < 101) {
                int d = prev[sum][squares_sum];
//                cout << d << ' ';
                to_out[pos++] = d;
                sum -= d;
                squares_sum -= d*d;
            }
            if (pos>100) {
                cout << "No solution" << endl;
            } else {
                for(int j = 0; j < pos; j++){
                    cout << to_out[j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}

