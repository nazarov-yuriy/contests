#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for(int i = 0 ; i < n; i++){
        if(a[i]>0 && a[i]>=a[n-k]) cnt++;
    }
    cout << cnt;
    return 0;
}