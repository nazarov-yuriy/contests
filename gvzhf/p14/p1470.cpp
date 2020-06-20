#include <iostream>

using namespace std;

#define LSB(i) ((i) & -(i))

int main() {
    int n;
    cin >> n;
    int m[n][n][n] = {};
    int fenwick[n][n][n] = {};
    while (true) {
        int t;
        cin >> t;
        if (t == 1) {
            int x2, y2, z2, k;
            cin >> x2 >> y2 >> z2 >> k;
            m[x2][y2][z2] += k;
            x2++;
            y2++;
            z2++;
            for (int x = x2; x <= n; x += LSB(x)) {
                for (int y = y2; y <= n; y += LSB(y)) {
                    for (int z = z2; z <= n; z += LSB(z)) {
                        fenwick[x - 1][y - 1][z - 1] += k;
                    }
                }
            }
        } else if (t == 2) {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            x2++;
            y2++;
            z2++;
//            long long int res_slow = 0;
//            for (int x = x1; x < x2; x++) {
//                for (int y = y1; y < y2; y++) {
//                    for (int z = z1; z < z2; z++) {
//                        res_slow += m[x][y][z];
//                    }
//                }
//            }
            long long int res[2][2][2] = {};
            for (int rx = 0; rx < 2; rx++) {
                for (int ry = 0; ry < 2; ry++) {
                    for (int rz = 0; rz < 2; rz++) {
                        for (int x = (rx ? x2 : x1); x > 0; x -= LSB(x)) {
                            for (int y = (ry ? y2 : y1); y > 0; y -= LSB(y)) {
                                for (int z = (rz ? z2 : z1); z > 0; z -= LSB(z)) {
//                                    cout << x - 1 << y - 1 << z - 1 << "=" << fenwick[x - 1][y - 1][z - 1] << endl;
                                    res[rx][ry][rz] += fenwick[x - 1][y - 1][z - 1];
                                }
                            }
                        }
                    }
                }
            }
//            cout << res_slow << endl;
            cout <<
                  res[1][1][1]
                 - res[1][1][0] - res[1][0][1] - res[0][1][1]
                 + res[0][0][1] + res[0][1][0] + res[1][0][0]
                 - res[0][0][0]
                 << endl;
        } else { // t == 3
            break;
        }
    }
    return 0;
}