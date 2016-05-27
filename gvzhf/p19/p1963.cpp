#include <iostream>

using namespace std;

int ll(int x, int y){
    return x*x+y*y;
}

int main() {
    int x[8], y[8];
    for(int i = 0; i < 4; i++){
        cin >> x[i] >> y[i];
        x[i+4] = x[i]*=2;
        y[i+4] = y[i]*=2;
    }
    int res = 0;
    for(int i = 0; i < 4; i++){
        if(ll(x[i+1]-x[i],y[i+1]-y[i]) == ll(x[i+3]-x[i],y[i+3]-y[i]) && ll(x[i+1]-x[i+2],y[i+1]-y[i+2]) == ll(x[i+3]-x[i+2],y[i+3]-y[i+2])){
            res++;
        }
    }
    for(int i = 0; i < 4; i++){
        int xc = (x[i]+x[i+3])/2, yc = (y[i]+y[i+3])/2;
        if(ll(x[i]-xc,y[i]-yc) == ll(x[i+3]-xc,y[i+3]-yc) && ll(x[i+1]-xc,y[i+1]-yc) == ll(x[i+2]-xc,y[i+2]-yc) && ll(x[i+1]-x[i],y[i+1]-y[i]) == ll(x[i+3]-x[i+2],y[i+3]-y[i+2])){
            res++;
        }
    }
    cout << res;
    return 0;
}