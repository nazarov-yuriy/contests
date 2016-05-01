#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

vector<string> &split10(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if (elems.size() && elems[elems.size() - 1].length() + 1 + item.length() <= 10) {
            elems[elems.size() - 1] = elems[elems.size() - 1] + " " + item;
        } else {
            elems.push_back(item);
        }
    }
    return elems;
}


vector<string> split10(const string &s, char delim) {
    vector<string> elems;
    split10(s, delim, elems);
    return elems;
}

int main() {
    int n, t;
    cin >> n;
    string line;
    array<vector<string>, 4> tuesday;
    array<vector<string>, 4> thursday;
    array<vector<string>, 4> saturday;
    for (int i = 0; i < n; i++) {
        string subj_name;
        getline(cin, subj_name); //dummy read after cin >>
        getline(cin, subj_name);
        cin >> line >> t;
        if ("Tuesday" == line) {
            tuesday[t - 1] = split10(subj_name, ' ');
            /*for (unsigned int j = 0; j < 5; j++) {
                if (subj_name.length() > j * 10) tuesday[t - 1].push_back(subj_name.substr(j * 10, 10));
            }*/
        }
        if ("Thursday" == line) {
            thursday[t - 1] = split10(subj_name, ' ');
            /*for (unsigned int j = 0; j < 5; j++) {
                if (subj_name.length() > j * 10) thursday[t - 1].push_back(subj_name.substr(j * 10, 10));
            }*/
        }
        if ("Saturday" == line) {
            saturday[t - 1] = split10(subj_name, ' ');
            /*for (unsigned int j = 0; j < 5; j++) {
                if (subj_name.length() > j * 10) saturday[t - 1].push_back(subj_name.substr(j * 10, 10));
            }*/
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << "+----------+----------+----------+" << endl;
        for (int j = 0;
             j < max(max(1, (int) tuesday[i].size()), max((int) thursday[i].size(), (int) saturday[i].size())); j++) {
            cout << '|' << setw(10) << left << (tuesday[i].size() > j ? tuesday[i][j] : "");
            cout << '|' << setw(10) << left << (thursday[i].size() > j ? thursday[i][j] : "");
            cout << '|' << setw(10) << left << (saturday[i].size() > j ? saturday[i][j] : "");
            cout << '|' << endl;
        }
    }
    cout << "+----------+----------+----------+";
    return 0;
}