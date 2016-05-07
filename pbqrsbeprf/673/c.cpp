#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int colors[n];
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
        colors[i]--;
    }
    int res[n] = {};
    for(int i = 0; i < n; i++){
        int counts[n] = {};
        int dominant = colors[i];
        for(int j = i; j < n; j++){
            int color = colors[j];
            counts[color]++;
            if ( counts[color] > counts[dominant] || (counts[color] >= counts[dominant] && color < dominant)) dominant = color;
            res[dominant]++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}