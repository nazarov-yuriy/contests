#include <iostream>
#include <set>

using namespace std;

int main() {
    string line;
    string gw;
    set<string> bays;
    getline(cin, gw);
    while(getline(cin, line)){
        if(line[0] == '#'){
            break;
        }
        unsigned long int m = line.find('-');
        bays.insert(line.substr(0, m));
        bays.insert(line.substr(m+1, line.length()-m-1));
    }
    bays.erase(gw);
    cout << bays.size();
    return 0;
}