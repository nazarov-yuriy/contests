#include <iostream>

using namespace std;

struct act {
    int r;
    int l;
    int f;
    int b;
};

int main() {
    int r[] = {0, 3, 6, 1, 5, 4, 2};
    act m[100] = {};
    int ai[] = {0, 2, 3, 2, 1, 1, 1};
    int bi[] = {0, 4, 4, 5, 2, 6, 4};
    int ci[] = {0, 6, 1, 6, 3, 6, 3};
    int di[] = {0, 5, 5, 4, 6, 2, 5};
    int poses[24];
    for (int i = 1; i <= 6; i++) {
        int a = i * 10 + ai[i], b = i * 10 + bi[i], c = i * 10 + ci[i], d = i * 10 + di[i];
        m[a] = {a % 10 + 10 * (b % 10), a % 10 + 10 * (d % 10), a / 10 + 10 * (c % 10), 10 * (a % 10) + r[a / 10]};
        m[b] = {b % 10 + 10 * (c % 10), b % 10 + 10 * (a % 10), b / 10 + 10 * (d % 10), 10 * (b % 10) + r[b / 10]};
        m[c] = {c % 10 + 10 * (d % 10), c % 10 + 10 * (b % 10), c / 10 + 10 * (a % 10), 10 * (c % 10) + r[c / 10]};
        m[d] = {d % 10 + 10 * (a % 10), d % 10 + 10 * (c % 10), d / 10 + 10 * (b % 10), 10 * (d % 10) + r[d / 10]};
        poses[i * 4 - 4 + 0] = a;
        poses[i * 4 - 4 + 1] = b;
        poses[i * 4 - 4 + 2] = c;
        poses[i * 4 - 4 + 3] = d;
    }
    int cost[8][8][100] = {}, from[8][8][100] = {}, vals[7] = {};
    int fx, fy, tx, ty;
    fx = getchar() - 'a';
    fy = getchar() - '1';
    getchar();
    tx = getchar() - 'a';
    ty = getchar() - '1';
    cin >> vals[2];
    cin >> vals[6];
    cin >> vals[3];
    cin >> vals[4];
    cin >> vals[1];
    cin >> vals[5];
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 100; j++) {
            cost[i / 8][i % 8][j] = 2000000000;
        }
    }
    cost[fx][fy][12] = vals[1];
    for (int l = 0; l < 6400; l++) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                for (int i = 0; i < 24; i++) {
                    int p = poses[i];
                    if (x < 7 && cost[x][y][p] + vals[m[p].r / 10] < cost[x + 1][y][m[p].r]) {
                        cost[x + 1][y][m[p].r] = cost[x][y][p] + vals[m[p].r / 10];
                        from[x + 1][y + 0][m[p].r] = (x + 0) * 1000 + (y + 0) * 100 + p;
                    }
                    if (y < 7 && cost[x][y][p] + vals[m[p].f / 10] < cost[x][y + 1][m[p].f]) {
                        cost[x][y + 1][m[p].f] = cost[x][y][p] + vals[m[p].f / 10];
                        from[x + 0][y + 1][m[p].f] = (x + 0) * 1000 + (y + 0) * 100 + p;
                    }
                    if (x > 0 && cost[x][y][p] + vals[m[p].l / 10] < cost[x - 1][y][m[p].l]) {
                        cost[x - 1][y][m[p].l] = cost[x][y][p] + vals[m[p].l / 10];
                        from[x - 1][y + 0][m[p].l] = (x + 0) * 1000 + (y + 0) * 100 + p;
                    }
                    if (y > 0 && cost[x][y][p] + vals[m[p].b / 10] < cost[x][y - 1][m[p].b]) {
                        cost[x][y - 1][m[p].b] = cost[x][y][p] + vals[m[p].b / 10];
                        from[x + 0][y - 1][m[p].b] = (x + 0) * 1000 + (y + 0) * 100 + p;
                    }
                }
            }
        }
    }
    int mi = 2000000000, mip = 0;
    for (int i = 0; i < 24; i++) {
        if(mi > cost[tx][ty][poses[i]]){
            mi = cost[tx][ty][poses[i]];
            mip = poses[i];
        }
    }
    int stack[6400];
    int st_pos = 0;
    while(tx != fx || ty != fy || 12 != mip){
        stack[st_pos++] = tx*10 + ty;
        //cout << (char)('a'+(char)tx) << ty+1 << ' ' << endl;
        int fr = from[tx][ty][mip];
        tx = fr / 1000;
        ty = (fr / 100)%10;
        mip = fr % 100;
    }
    cout << mi << ' ' << (char)('a'+(char)fx) << fy+1 << ' ';
    while(st_pos-->0){
        cout << (char)('a'+stack[st_pos]/10) << stack[st_pos]%10+1 << ' ';
    }
    return 0;
}