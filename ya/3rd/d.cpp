#include <iostream>

using namespace std;

int main() {
    long long int l, l2 = 1, c, r, r2 = 1;
    char color;
    string t;
    cout << "? 0" << endl;
    cin >> t;
    color = t[0];
    for(int i = 1; i < 63; i++){
        cout << "? " << (1LL<<i)-1 << endl;
        cin >> t;
        if(t[0] != color) {
            r2 = (1LL<<(i-1));
            i--;
            r = r2;
            for(;i>=0;i--){
                cout << "? " << (1LL<<i)+r-1 << endl;
                cin >> t;
                if(t[0] == color) r += (1LL<<i);
            }
            break;
        }
    }
    for(int i = 1; i < 63; i++){
        cout << "? " << -(1LL<<i)+1 << endl;
        cin >> t;
        if(t[0] != color) {
            l2 = (1LL<<(i-1));
            i--;
            l = l2;
            for(;i>=0;i--){
                cout << "? " << -(1LL<<i)-l+1 << endl;
                cin >> t;
                if(t[0] == color) l += (1LL<<i);
            }
            break;
        }
    }
    cout << "! " << r+l-1 << endl;
    return 0;
}