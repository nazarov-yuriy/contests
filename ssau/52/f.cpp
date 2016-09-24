#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct abcp {
    int a;
    int b;
    int c;
    int p;
};

bool cmpa(abcp f, abcp s) {
    return f.a < s.a;
}

bool cmpb(abcp f, abcp s) {
    return f.b < s.b;
}

bool cmpc(abcp f, abcp s) {
    return f.c < s.c;
}

int main() {
    unsigned int n;
    cin >> n;
    vector<abcp> data;
    data.resize(n);
    set<int> res;
    for (int i = 0; i < n; i++) {
        res.insert(i);
        cin >> data[i].a >> data[i].b >> data[i].c;
        data[i].p = i;
    }
    int ma[n], mb[n], mc[n];
    //a
    sort(data.begin(), data.end(), cmpa);
    mb[0] = data[0].b;
    mc[0] = data[0].c;
    for (int i = 1; i < n; i++) {
        mb[i] = min(mb[i - 1], data[i].b);
        mc[i] = min(mc[i - 1], data[i].c);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (mb[i] < data[i].b) {
            res.erase(data[i].p);
        }
        if (mc[i] < data[i].c) {
            res.erase(data[i].p);
        }
    }
    //b
    sort(data.begin(), data.end(), cmpb);
    ma[0] = data[0].a;
    mc[0] = data[0].c;
    for (int i = 1; i < n; i++) {
        ma[i] = min(ma[i - 1], data[i].a);
        mc[i] = min(mc[i - 1], data[i].c);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (ma[i] < data[i].a) {
            res.erase(data[i].p);
        }
        if (mc[i] < data[i].c) {
            res.erase(data[i].p);
        }
    }
    //c
    sort(data.begin(), data.end(), cmpc);
    ma[0] = data[0].a;
    mb[0] = data[0].b;
    for (int i = 1; i < n; i++) {
        ma[i] = min(ma[i - 1], data[i].a);
        mb[i] = min(mb[i - 1], data[i].b);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (ma[i] < data[i].a) {
            res.erase(data[i].p);
        }
        if (mb[i] < data[i].b) {
            res.erase(data[i].p);
        }
    }
    cout << res.size() << endl;
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it + 1 << ' ';
    }
    return 0;
}