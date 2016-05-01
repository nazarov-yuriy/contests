#include <iostream>

using namespace std;

struct state {
    int tact;
    int x;
    int dir_x;
    int y;
    int dir_y;
    int curr;
    int reg[26];
};

int main() {
    int h, w;
    cin >> h >> w;
    char prog[h][w];
    string line;
    getline(cin, line);
    for (int i = 0; i < h; i++) {
        getline(cin, line);
        for (int j = 0; j < w; j++) {
            prog[i][j] = line.c_str()[j];
        }
    }
    int n, last_in;
    cin >> n;
    state st = {
            .tact = 0,
            .x = 0,
            .dir_x = 1,
            .y = 0,
            .dir_y = 0,
            .curr = 0,
            .reg = {0}
    };
    while (1) {
        int t;
        char op = prog[st.y][st.x];
        switch (op) {
            case '^':
                st.dir_x = 0;
                st.dir_y = -1;
                break;
            case 'v':
                st.dir_x = 0;
                st.dir_y = 1;
                break;
            case '>':
                st.dir_x = 1;
                st.dir_y = 0;
                break;
            case '<':
                st.dir_x = -1;
                st.dir_y = 0;
                break;
            case '.':
                break;
            case 'A'...'Z':
                t = st.curr;
                st.curr = st.reg[op - 'A'];
                st.reg[op - 'A'] = t;
                break;
            case '?':
                if(n > 0) {
                    cin >> last_in;
                    st.curr = last_in;
                    n--;
                }else{
                    st.curr = last_in;
                }
                break;
            case '!':
                cout << st.curr << endl;
                st.curr = 0;
                break;
            case '+':
                st.curr++;
                break;
            case '-':
                st.curr--;
                break;
            case '@':
                if (st.curr == 0) {
                    t = st.dir_x;
                    st.dir_x = st.dir_y;
                    st.dir_y = -t;
                } else {
                    t = st.dir_x;
                    st.dir_x = -st.dir_y;
                    st.dir_y = t;
                }
                break;
            case '#':
                return 0;
                break;
            default:
                break;
        }
        if (abs(st.curr) > 100000) {
            cout << "OVERFLOW ERROR" << endl;
            return 0;
        }
        st.x += st.dir_x;
        st.y += st.dir_y;
        if (st.x < 0 || w <= st.x || st.y < 0 || h <= st.y) {
            cout << "RUNTIME ERROR" << endl;
            return 0;
        }
        st.tact++;
        if (st.tact >= 1000000) {
            cout << "TIME LIMIT EXCEEDED" << endl;
            return 0;
        }
    }
    return 0;
}