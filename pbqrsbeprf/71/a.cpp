#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    for(int i = 0; i < n; i++){
        getline(cin, line);
        if(line.length() > 10){
            cout << line[0] << line.length()-2 << line[line.length()-1] << endl;
        }else{
            cout << line << endl;
        }
    }
    return 0;
}
