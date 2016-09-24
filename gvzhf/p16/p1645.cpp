#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n + 1], res_min[n + 1], res_max[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int t = arr[i];
        res_min[t] = 1;
        res_max[t] = n;
        for (int j = 0; j < i; j++)
            if (arr[j] > t)
                res_min[t]++;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < t)
                res_max[t]--;
    }
    for (int i = 1; i <= n; i++) {
        cout << res_min[i] << ' ' << res_max[i] << endl;
    }
    return 0;
}