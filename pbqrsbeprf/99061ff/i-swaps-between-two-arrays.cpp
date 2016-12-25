#include <iostream>
#include <vector>

using namespace std;

struct pos {
    unsigned arr : 1;
    unsigned idx : 31;
};

struct pair_pos {
    short filled;
    pos p[2];
};

struct mv {
    unsigned from;
    unsigned to;
};

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int arr[2][n] = {{}};
    pair_pos pairs[n] = {};
    vector<mv> mvs;
    for (unsigned j = 0; j < 2; j++) {
        for (unsigned i = 0; i < n; i++) {
            cin >> arr[j][i];
            arr[j][i]--;
            pairs[arr[j][i]].p[pairs[arr[j][i]].filled].arr = j;
            pairs[arr[j][i]].p[pairs[arr[j][i]].filled].idx = i;
            pairs[arr[j][i]].filled++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (pairs[i].p[0].arr == pairs[i].p[1].arr) {
            int lv = arr[1 - pairs[i].p[0].arr][n - 1];
            if (pairs[lv].p[0].arr == 1 - pairs[i].p[0].arr) {
                unsigned f = pairs[i].p[0].arr ? pairs[lv].p[0].idx : pairs[i].p[0].idx;
                unsigned t = pairs[i].p[0].arr ? pairs[i].p[0].idx : pairs[lv].p[0].idx;
                mvs.push_back({f, t});
                swap(arr[0][f], arr[1][t]);
                swap(pairs[lv].p[0], pairs[i].p[0]);
            } else {
                unsigned f = pairs[i].p[0].arr ? pairs[lv].p[1].idx : pairs[i].p[0].idx;
                unsigned t = pairs[i].p[0].arr ? pairs[i].p[0].idx : pairs[lv].p[1].idx;
                mvs.push_back({f, t});
                swap(arr[0][f], arr[1][t]);
                swap(pairs[lv].p[1], pairs[i].p[0]);
            }
        }
        if (pairs[i].p[0].arr) swap(pairs[i].p[0], pairs[i].p[1]);

        int cv;
        cv = arr[0][i];
        bool redo = (cv == i);
        if (!redo) {
            if (pairs[cv].p[0].arr == 0 && pairs[cv].p[0].idx == i) {
                unsigned f = pairs[cv].p[0].idx;
                unsigned t = pairs[i].p[1].idx;
                mvs.push_back({f, t});
                swap(arr[0][f], arr[1][t]);
                swap(pairs[cv].p[0], pairs[i].p[1]);
            } else {
                unsigned f = pairs[cv].p[1].idx;
                unsigned t = pairs[i].p[1].idx;
                mvs.push_back({f, t});
                swap(arr[0][f], arr[1][t]);
                swap(pairs[cv].p[1], pairs[i].p[1]);
            }
        }

        cv = arr[1][i];
        if (pairs[cv].p[0].arr == 1 && pairs[cv].p[0].idx == i) {
            unsigned f = pairs[i].p[0].idx;
            unsigned t = pairs[cv].p[0].idx;
            mvs.push_back({f, t});
            swap(arr[0][f], arr[1][t]);
            swap(pairs[cv].p[0], pairs[i].p[0]);
        } else {
            unsigned f = pairs[i].p[0].idx;
            unsigned t = pairs[cv].p[1].idx;
            mvs.push_back({f, t});
            swap(arr[0][f], arr[1][t]);
            swap(pairs[cv].p[1], pairs[i].p[0]);
        }

        if (redo) {
            cv = arr[0][i];
            if (pairs[cv].p[0].arr == 0 && pairs[cv].p[0].idx == i) {
                unsigned f = pairs[cv].p[0].idx;
                unsigned t = pairs[i].p[1].idx;
                mvs.push_back({f, t});
                swap(arr[0][f], arr[1][t]);
                swap(pairs[cv].p[0], pairs[i].p[1]);
            } else {
                unsigned f = pairs[cv].p[1].idx;
                unsigned t = pairs[i].p[1].idx;
                mvs.push_back({f, t});
                swap(arr[0][f], arr[1][t]);
                swap(pairs[cv].p[1], pairs[i].p[1]);
            }
        }
    }
    cout << mvs.size() << endl;
    for (auto it = mvs.begin(); it != mvs.end(); ++it) {
        cout << it->from + 1 << ' ' << it->to + 1 << endl;
    }
    return 0;
}