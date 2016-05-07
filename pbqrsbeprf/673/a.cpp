#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int last = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(t - last > 15) {
            cout << min(last + 15, 90);
            return 0;
        } else {
            last = t;
        }
    }
    cout << min(last + 15, 90);
    return 0;
}
