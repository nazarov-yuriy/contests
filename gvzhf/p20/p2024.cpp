#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

long long unsigned int c(int n, int k) {
    long long unsigned int res = 1;
    k = min(k, n-k);
    for (int i = n; i > (n-k) ; i--) {
        res *= i;
    }
    for (int i = k; i > 0; i--) {
        res /= i;
    }
    return res;
}

int main() {
    int k;
    std::array<int, 26> counts = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string line;
    getline(cin, line);
    cin >> k;
    k--;
    for (int i = 0; i < line.length(); i++) {
        counts[line.c_str()[i] - 'a']++;
    }
    std::sort(counts.begin(), counts.end(), std::greater<int>());
    int first = 0, last = 0;
    if(counts[k] == 0){
        cout << line.size() << " " << 1;
        return 0;
    }
    for (int i = 0; i < 26; i++) {
        if (counts[i] == counts[k]) last = i;
        if (counts[26 - i - 1] == counts[k]) first = 26 - i - 1;
    }
    long long unsigned size = 0;
    for (int i = 0; i <= k; i++) {
        size += counts[i];
    }
    cout << size << " " << c(last - first + 1, k - first + 1);
    return 0;
}


















