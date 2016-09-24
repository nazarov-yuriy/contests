#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

struct node {
    bool dead;
    set<int> links;
};

int main() {
    int n, res, max_res = 0;
    cin >> n;
    map<string, vector<int>> participants;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        participants[str].push_back(i);
        cin >> str;
        participants[str].push_back(i);
        cin >> str;
        participants[str].push_back(i);
    }
    for (int f = 0; f < n; f++) {
        for (int g = 0; g < n; g++) {
            res = n;
            node nodes[20];
            for (int i = 0; i < n; i++) nodes[i] = {};
            for (auto it = participants.begin(); it != participants.end(); ++it) {
                if (it->second.size() > 1) {
                    for (auto jt = it->second.begin(); (jt + 1) != it->second.end(); ++jt) {
                        for (auto kt = jt + 1; kt != it->second.end(); ++kt) {
                            nodes[*jt].links.insert(*kt);
                            nodes[*kt].links.insert(*jt);
                        }
                    }
                }
            }
            //for (int i = 0; i < n; i++) {
            //    cout << nodes[i].links.size() << endl;
            //}
            while (1) {
                int max_links = 0, max_pos = 0;
                for (int i = 0; i < n; i++) {
                    if (!nodes[i].dead && nodes[i].links.size() > max_links) {
                        max_links = nodes[i].links.size();
                        max_pos = i;
                    }
                }
                if (0 == max_links)
                    break;
                else {
                    if (!nodes[f].dead && nodes[f].links.size())
                        max_pos = f;
                    else if (!nodes[g].dead && nodes[g].links.size())
                        max_pos = g;
                    res--;
                    //cout << "kill " << max_pos << endl;
                    nodes[max_pos].dead = true;
                    for (auto it = nodes[max_pos].links.begin(); it != nodes[max_pos].links.end(); ++it) {
                        nodes[*it].links.erase(max_pos);
                    }
                }
                //for (int i = 0; i < n; i++) {
                //    cout << nodes[i].links.size() << endl;
                //}
            }
            max_res = max(max_res, res);
        }
    }
    cout << max_res << endl;
    return 0;
}