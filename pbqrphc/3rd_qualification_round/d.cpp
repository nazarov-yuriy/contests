#include <iostream>
#include <set>

using namespace std;

#define SZ 100002
int p[SZ] = {};
int del[SZ] = {1, 1};
int dep[SZ] = {1, 1};
int cache_p[SZ] = {};
int cache_d[SZ] = {};
set<int> on_depth[SZ];

#define STEP 64

int depth(int a) {
    int depth_a = 0, oa = a, prev = 0, d = 0;
    while (!dep[a]) {
        a = p[a];
        depth_a++;
    }
    int dc = depth_a + dep[a];
    a = oa;
    while (!dep[a]) {
        d += del[a];
        if (0 == (dc % STEP)) {
            if (prev) {
                cache_p[prev] = a;
                cache_d[prev] = d;
                on_depth[dc].insert(prev);
            }
            d = 0;
            prev = a;
        }
        dep[a] = dc--;
        a = p[a];
    }
    return dep[oa];
}

int dist(int a, int b) {
    int depth_a = depth(a), depth_b = depth(b), res = 0;
    while (depth_a > depth_b) {
        if (0 == (depth_a % STEP) && depth_a > depth_b + STEP && cache_p[a]) {
            res += cache_d[a];
            a = cache_p[a];
            depth_a -= STEP;
        } else {
            a = p[a];
            depth_a--;
            res += del[a];
        }
    }
    while (depth_b > depth_a) {
        if (0 == (depth_b % STEP) && depth_b > depth_a + STEP && cache_p[b]) {
            res += cache_d[b];
            b = cache_p[b];
            depth_b -= STEP;
        } else {
            b = p[b];
            depth_b--;
            res += del[b];
        }
    }
    while (a != b || !del[a]) {
        a = p[a];
        res += del[a];
        b = p[b];
        res += del[b];
    }
    return res;
}

int main() {
    int n, q;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        del[i] = 1;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int cmd, a, b;
        cin >> cmd >> a;
        if (cmd == 2) {
            int ca = a;
            for (int j = 0; j < STEP; j++) {
                if (ca == 1) break;
                if (0 == (depth(ca) % STEP)) {
                    for (auto it = on_depth[depth(ca)].begin(); it != on_depth[depth(ca)].end(); ++it) {//int k = 2; k <= n; k++){
                        int k = *it;
                        if (cache_p[k] == ca) {
                            int cca = k;
                            while (cca != ca && cca != a && cca != 1) { cca = p[cca]; };
                            if (cca == a) cache_d[k]--;
                        }
                    }
                    break;
                }
                ca = p[ca];
            }
            del[a] = 0;
        } else {
            cin >> b;
            cout << dist(a, b) << endl;
        }
    }
    return 0;
}