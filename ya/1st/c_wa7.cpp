#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dif[10];
int best_worst(int *prize){
    int best = -2000000000;
    for(int a = 1; a < 10; a++){
        for(int b = 2; b < 10; b++){
            if(a!=b){
                for(int c = 3; c < 10; c++){
                    if(a!=c&&b!=c){
                        for(int d = 0; d < 10; d++){
                            if(a!=d&&b!=d&&c!=d){
                                for(int e = 0; e < 10; e++){
                                    if(a!=e&&b!=e&&c!=e&&d!=e){
                                        for(int f = 0; f < 10; f++){
                                            if(a!=f&&b!=f&&c!=f&&d!=f&&e!=f){
                                                for(int g = 0; g < 10; g++){
                                                    if(a!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g){
                                                        for(int h = 0; h < 10; h++){
                                                            if(a!=h&&b!=h&&c!=h&&d!=h&&e!=h&&f!=h&&g!=h){
                                                                for(int i = 0; i < 10; i++){
                                                                    if(a!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i){
                                                                        for(int j = 0; j < 10; j++){
                                                                            if(a!=j&&b!=j&&c!=j&&d!=j&&e!=j&&f!=j&&g!=j&&h!=j&&i!=j){
                                                                                int worst0,worst1,worst2;
                                                                                worst0 = min(
                                                                                        min(prize[a]+dif[0], prize[b]+dif[1]),
                                                                                        min(prize[c]+dif[2], prize[d]+dif[3])
                                                                                );
                                                                                worst1 = min(
                                                                                        min(prize[e]+dif[4], prize[f]+dif[5]),
                                                                                        min(prize[g]+dif[6], prize[h]+dif[7])
                                                                                );
                                                                                worst2 = min(prize[i]+dif[8], prize[j]+dif[9]);
                                                                                best = max(best, min(min(worst0,worst1),worst2));
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return best;
}

int main() {
    int max_p[] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> in;
    for(int i = 0; i < 10; i++){
        int t;
        cin >> t;
        in.push_back(t);
    }
    sort(in.begin(), in.end(), greater<int>());
    for(int i = 0; i < 10; i++){
        dif[i] = in[i];
    }
    int prize[] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24};
    int best = best_worst(prize);

        for(int i = 30; i >= 0; i--){
            if(max_p[i] > best){
                if(i==30){
                    cout << 1000;
                    return 0;
                }else{
                    cout << i+1;
                    return 0;
                }
            } else if(max_p[i] == best){
                int pos = 0;
                for(int j = 0; j < 11; j++){
                    if(i!=j)
                        prize[pos++] = max_p[j];
                }
                if(max_p[i] > best_worst(prize)){
                    cout << i+1;
                    return 0;
                }
            }
        }
        cout << 0;

    return 0;
}