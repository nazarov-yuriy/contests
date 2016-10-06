#include <iostream>

using namespace std;

string strs[3];

bool is_win(char c) {
    if (strs[0][0] == c && strs[0][1] == c && strs[0][2] == c) return true;
    if (strs[1][0] == c && strs[1][1] == c && strs[1][2] == c) return true;
    if (strs[2][0] == c && strs[2][1] == c && strs[2][2] == c) return true;
    if (strs[0][0] == c && strs[1][0] == c && strs[2][0] == c) return true;
    if (strs[0][1] == c && strs[1][1] == c && strs[2][1] == c) return true;
    if (strs[0][2] == c && strs[1][2] == c && strs[2][2] == c) return true;
    if (strs[0][0] == c && strs[1][1] == c && strs[2][2] == c) return true;
    if (strs[0][2] == c && strs[1][1] == c && strs[2][0] == c) return true;
    return false;
}

int main() {
    string copy[3];
    cin >> copy[0] >> copy[1] >> copy[2];
    int x[3], y[3], pos = 0, second = 0, third = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (copy[i][j] == '#') {
                y[pos] = i;
                x[pos++] = j;
            }
        }
    }

    for (int i = 0; i < 3; i++) strs[i] = copy[i];
    strs[y[0]][x[0]] = 'X';
    if (is_win('X')) {
        cout << "Crosses win";
        return 0;
    }
    strs[y[1]][x[1]] = 'O';
    strs[y[2]][x[2]] = 'X';
    if (is_win('O')) second |= 1;
    if (is_win('X')) third |= 1;

    strs[y[1]][x[1]] = 'X';
    strs[y[2]][x[2]] = 'O';
    if (is_win('O')) second |= 1;
    if (is_win('X')) third |= 2;

    for (int i = 0; i < 3; i++) strs[i] = copy[i];
    strs[y[1]][x[1]] = 'X';
    if (is_win('X')) {
        cout << "Crosses win";
        return 0;
    }
    strs[y[0]][x[0]] = 'O';
    strs[y[2]][x[2]] = 'X';
    if (is_win('O')) second |= 2;
    if (is_win('X')) third |= 4;

    strs[y[0]][x[0]] = 'X';
    strs[y[2]][x[2]] = 'O';
    if (is_win('O')) second |= 2;
    if (is_win('X')) third |= 8;

    for (int i = 0; i < 3; i++) strs[i] = copy[i];
    strs[y[2]][x[2]] = 'X';
    if (is_win('X')) {
        cout << "Crosses win";
        return 0;
    }
    strs[y[1]][x[1]] = 'O';
    strs[y[0]][x[0]] = 'X';
    if (is_win('O')) second |= 4;
    if (is_win('X')) third |= 16;

    strs[y[1]][x[1]] = 'X';
    strs[y[0]][x[0]] = 'O';
    if (is_win('O')) second |= 4;
    if (is_win('X')) third |= 32;

    if (second == 7) {
        cout << "Ouths win";
    } else if (((third & 3) == 3 && !(second & 1)) || ((third & 12) == 12 && !(second & 2)) ||
               ((third & 48) == 48 && !(second & 4))) {
        cout << "Crosses win";
    } else {
        cout << "Draw";
    }
    return 0;
}