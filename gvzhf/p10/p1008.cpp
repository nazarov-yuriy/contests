#include <iostream>
#include <deque>
#include <sstream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);

    char pic[12][12] = {};


    if (s.length() <= 2) {
        int n, mx = 12, my = 12;
        deque<pair<int, int>> d;
        ss >> n;
        for (int i = 0; i < n; i++) {
            int y, x;
            cin >> x >> y;
            pic[y][x] = 1;
            if (x < mx) {
                mx = x;
                my = y;
            } else if (x == mx) {
                my = min(my, y);
            }
        }
        d.push_back({mx, my});
        pic[my][mx] = 0;
        cout << mx << ' ' << my << endl;
        while (!d.empty()) {
            int x = d.front().first, y = d.front().second;
            d.pop_front();
            if (pic[y][x + 1]) {
                d.push_back({x + 1, y});
                pic[y][x + 1] = 0;
                cout << 'R';
            }
            if (pic[y + 1][x]) {
                d.push_back({x, y + 1});
                pic[y + 1][x] = 0;
                cout << 'T';
            }
            if (pic[y][x - 1]) {
                d.push_back({x - 1, y});
                pic[y][x - 1] = 0;
                cout << 'L';
            }
            if (pic[y - 1][x]) {
                d.push_back({x, y - 1});
                pic[y - 1][x] = 0;
                cout << 'B';
            }
            cout << (d.empty() ? '.' : ',') << endl;
        }
    } else {
        int x, y, cnt = 1;
        ss >> x >> y;
        pic[y][x] = 1;
        getline(cin, s);
        deque<pair<int, int>> d;
        d.push_back({x, y});
        while (s != ".") {
            x = d.front().first;
            y = d.front().second;
            d.pop_front();
            for (int i = 0; s[i] > 'A'; i++) {
                if (s[i] == 'R') {
                    cnt++;
                    pic[y][x + 1] = 1;
                    d.push_back({x + 1, y});
                }
                if (s[i] == 'L') {
                    cnt++;
                    pic[y][x - 1] = 1;
                    d.push_back({x - 1, y});
                }
                if (s[i] == 'T') {
                    cnt++;
                    pic[y + 1][x] = 1;
                    d.push_back({x, y + 1});
                }
                if (s[i] == 'B') {
                    cnt++;
                    pic[y - 1][x] = 1;
                    d.push_back({x, y - 1});
                }
            }
            getline(cin, s);
        }
        cout << cnt << endl;
        for (int xi = 0; xi < 12; xi++) {
            for (int yi = 0; yi < 12; yi++) {
                if (pic[yi][xi]) {
                    cout << xi << ' ' << yi << endl;
                }
            }
        }
    }
    return 0;
}