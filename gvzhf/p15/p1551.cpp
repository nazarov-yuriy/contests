#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> counts;
    string str;
    int maxc = 0;
    for(int i = 0; i < (1<<n);i++){
        getline(cin, str);
        cin >> str;
        cin >> str;
        if(counts.count(str)){
            counts[str]++;
            maxc = max(maxc, counts[str]);
        }else{
            counts[str]=1;
        }
    }
    for(int i = 1; i <= n; i++){
        if(maxc > (1<<(n-i))){
            cout << i-1;
            return 0;
        }
    }
    cout << n;
    //for(auto it = counts.begin(); it != counts.end(); ++it){ cout << it->first << ' ' << it->second << endl; }
    return 0;
}
