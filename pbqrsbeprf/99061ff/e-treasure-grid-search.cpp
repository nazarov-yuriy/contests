#include <iostream>

using namespace std;

int main(){
    int n, m, d00, dn0, d0m;
    cin >> n >> m;
    cout << "? " << 0 << ' ' << 0 << endl;
    cin >> d00;
    cout << "? " << n << ' ' << 0 << endl;
    cin >> dn0;
    cout << "? " << 0 << ' ' << m << endl;
    cin >> d0m;
    cout << "! " << (d00+d0m-m)/2 << ' ' << (d00+dn0-n)/2;
    return 0;
}