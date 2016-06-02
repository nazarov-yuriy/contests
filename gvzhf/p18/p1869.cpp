#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }

    long long int pass_f = 0, pass_b = 0, mpass_f = 0, mpass_b = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < i; j++){
            pass_b -= m[i][j];
            pass_f -= m[j][i];
        }
        for(int j = i+1; j < n; j++){
            pass_b += m[j][i];
            pass_f += m[i][j];
        }
        mpass_b = max(mpass_b, pass_b);
        mpass_f = max(mpass_f, pass_f);
    }
    cout << (max(mpass_f, mpass_b)+35)/36;
    return 0;
}