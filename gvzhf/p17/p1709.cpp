#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    unsigned int n, d, a;
    string line;
    cin >> n >> d >> a;
    getline(std::cin, line); //skip \n
    vector<set<int>> links(n);
    char original[n][n];
    char optimized[n][n];
    set<int> remaining;
    for (int i = 0; i < n; i++) {
        remaining.insert(i);
        getline(std::cin, line);
        for (int j = 0; j < n; j++) {
            optimized[i][j] = '0';
            original[i][j] = line.c_str()[j];
            if (line.c_str()[j] == '1') {
                links[i].insert(j);
            }
        }
    }
    vector<int> stack;
    int current = *(remaining.begin());
    remaining.erase(current);
    stack.push_back(current);
    do {
        bool found = false;
        while (1) {
            for (auto it = links[current].begin(); it != links[current].end(); ++it) {
                if (remaining.count(*it)) {
                    optimized[current][*it] = optimized[*it][current] = '1';
                    current = *it;
                    stack.push_back(current);
                    remaining.erase(current);
                    found = true;
                    break;
                }
            }
            if (!found && stack.size() > 1) {
                stack.pop_back();
                current = stack[stack.size() - 1];
            } else {
                break;
            }
        }
        if (!found) {
            int next = *(remaining.begin());
            optimized[current][next] = optimized[next][current] = '1';
            current = next;
            stack.push_back(current);
            remaining.erase(current);
        }
    } while (!remaining.empty());
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << optimized[i][j];
        }
        cout << endl;
    }*/

    long long int cost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (original[i][j] == '0' && optimized[i][j] == '1') {
                //cout << 'a';
                cost += a;
            } else if (original[i][j] == '1' && optimized[i][j] == '0') {
                //cout << 'd';
                cost += d;
            } else {
                //cout << '0';
            }
        }
        //cout << endl;
    }
    cout << cost / 2 << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (original[i][j] == '0' && optimized[i][j] == '1') {
                cout << 'a';
                //cost += a;
            } else if (original[i][j] == '1' && optimized[i][j] == '0') {
                cout << 'd';
                //cost += d;
            } else {
                cout << '0';
            }
        }
        cout << endl;
    }
    return 0;
}