#include <iostream>
#include <array>

using namespace std;

int main(){
    const int N = 1000001;
    long long int l, r;
    cin >> l >> r;
    array<int, N> erato;
    array<int, N> erato_powers;
    for(auto it = erato.begin(); it != erato.end(); ++it){
        *it = 1;
    }
    for(long long int i = 2; i < N; i++){
        if(erato[i]){
            for(long long int j=i*i; j < N; j+=i){
                erato[j] = 0;
            }
        }
    }
    for(long long int i = 0; i < N; i++){
        erato_powers[i] = erato[i];
    }
    for(long long int i = 2; i < N; i++){
        for(long long int j = i*i, power = 2; j < N; j*=i, power++){
            if(erato[power*2+1] && erato[i])erato_powers[j] = 1;
        }
    }

    long long int same = r - l + 1;
    for(long long int i = 1; i < N; i++){
        if(erato_powers[i] && l <= i*i && i*i <= r){
            same--;
        }
    }
    cout << same;
    return 0;
}