#include <iostream>

using namespace std;

int a[21];
string res;
unsigned int n;
void db(int t, int p){
    if (t > n){
        if(0 == n % p)
            for(int i = 1; i<=p;i++)
                res += (char)('0'+a[i]);
    }else{
        a[t] = a[t-p];
        db(t + 1, p);
        for(int j = a[t - p] + 1;j<2;j++){
            a[t] = j;
            db(t+1, t);
        }
    }
}

int main(){
    cin >> n;
    db(1, 1);
    cout << res << res.substr(1 << n - n, n-1);
    return 0;
}