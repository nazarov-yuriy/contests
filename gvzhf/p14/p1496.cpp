#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n, i;
	unordered_map<string,int> counts;
	cin >> n;
	for(;n>0;n--){
	    string name;
	    cin >> name;
        counts[name]++;
	}
	for (auto it = counts.begin(); it != counts.end(); ++it){
	    if (it->second >= 2) cout << it->first << endl;
	}

	return 0;
}
