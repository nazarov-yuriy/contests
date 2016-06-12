#include <iostream>
#include <vector>

using namespace std;

#define STEP 256

struct node {
    int parent;
    vector<int> children;
    long long int salary;
    long long int bonus;
    long long int sum;
    int tin;
    int tout;
};

int t = 0;

static void dfs(node nodes[], int nd, int link[]) {
    link[t] = nd;
    nodes[link[STEP * (t / STEP)]].sum += nodes[nd].salary;
    nodes[nd].tin = t++;
    for (auto i : nodes[nd].children) {
        dfs(nodes, i, link);
    }
    nodes[nd].tout = t;
}

int main() {
    int n, q, s;
    cin >> n >> q >> s;
    node nodes[n];
    int link[n] = {};
    nodes[0].salary = s;
    nodes[0].sum = 0;
    nodes[0].bonus = 0;
    nodes[0].children = {};
    for (int i = 1; i < n; i++) {
        nodes[i].sum = 0;
        nodes[i].bonus = 0;
        nodes[i].children = {};
        cin >> nodes[i].parent >> nodes[i].salary;
        nodes[nodes[i].parent].children.push_back(i);
    }
    dfs(nodes, 0, link);
    for (int i = 0; i < q; i++) {
        string cmd;
        long long int x, y, z;
        cin >> cmd >> x >> y >> z;
        if (cmd == "employee") {
            if (nodes[x].salary + nodes[link[STEP * (nodes[x].tin / STEP)]].bonus < y) {
                nodes[x].salary += z;
                nodes[link[STEP * (nodes[x].tin / STEP)]].sum += z;
            }
        } else {
            long long int sum = 0;
            for (int j = nodes[x].tin; j < nodes[x].tout; j++) {
                if (0 == (j % STEP) && j + STEP < nodes[x].tout) {
                    sum += nodes[link[j]].sum + nodes[link[j]].bonus * STEP;
                    j += STEP - 1;
                } else {
                    sum += nodes[link[j]].salary + nodes[link[STEP * (j / STEP)]].bonus;
                }
            }
            if (sum < y * (nodes[x].tout - nodes[x].tin)) {
                for (int j = nodes[x].tin; j < nodes[x].tout; j++) {
                    if (0 == (j % STEP) && j + STEP < nodes[x].tout) {
                        nodes[link[j]].bonus += z;
                        j += STEP - 1;
                    } else {
                        nodes[link[j]].salary += z;
                        nodes[link[STEP * (j / STEP)]].sum += z;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << nodes[i].salary + nodes[link[STEP * (nodes[i].tin / STEP)]].bonus << endl;
    }
    return 0;
}