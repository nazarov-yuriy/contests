#include <iostream>
#include <list>
#include <array>

using namespace std;

struct entity {
    bool isBuster;
    int number;
    char type;
};

int main() {
    int n;
    string line;
    cin >> n;
    getline(cin, line);
    getline(cin, line);
    list <entity> entities;
    int busters = 0, ghosts = 0;
    int targets[n];
    for (int i = 0; i < 2 * n; i++) {
        if ('A' <= line.c_str()[i] && line.c_str()[i] <= 'Z') {
            entity en = {
                    .isBuster = true,
                    .number = busters++,
                    .type = (char) tolower(line.c_str()[i])
            };
            entities.push_back(en);
        } else {
            entity en = {
                    .isBuster = false,
                    .number = ghosts++,
                    .type = (char) tolower(line.c_str()[i])
            };
            entities.push_back(en);
        }
    }
    /*for (auto it = entities.begin(); it != entities.end(); ++it) {
        cout << it->isBuster << " " << it->number << " " << it->type << " " << endl;
    }*/
    while (entities.size()) {
        auto curr = entities.begin();
        auto next = curr;
        next++;
        bool found = false;
        while (next != entities.end()) {
            auto curr_copy = curr;
            auto next_copy = next;
            if (curr->type == next->type && curr->isBuster != next->isBuster) {
                if (curr->isBuster) {
                    targets[curr->number] = next->number;
                } else {
                    targets[next->number] = curr->number;
                }
                curr++;
                curr++;
                next++;
                if (next != entities.end()) next++;
                entities.erase(curr_copy);
                entities.erase(next_copy);
                found = true;
            } else {
                next++;
                curr++;
            }
        }
        if(entities.size() && !found){
            cout << "Impossible";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (targets[i]+1) << " ";
    }
    return 0;
}
