#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, max_score = -1000000;
    string first;
    cin >> n;
    map<string, int> scores, scores1;
    string inpn[n];
    int inps[n];
    for(int i = 0; i < n; i++){
        cin >> inpn[i] >> inps[i];
        scores[inpn[i]] += inps[i];
    }
    for(auto it = scores.begin(); it != scores.end(); ++it){
        max_score = max(max_score, it->second);
    }
    for(int i = 0; i < n;i++){
        scores1[inpn[i]] += inps[i];
        if(scores[inpn[i]] >= max_score && scores1[inpn[i]] >= max_score){
            cout << inpn[i];
            return 0;
        }
    }
    return 0;
}