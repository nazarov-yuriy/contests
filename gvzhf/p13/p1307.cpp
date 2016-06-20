#include <iostream>
#include <unistd.h>

using namespace std;

string beg = R"(//CPP
#include <iostream>
char *d[] = {"\n","\"","\\"," the "," of "," and "," to "," a "," in "," that "," is "," it "," or "};char *s=")",
        m1 = R"(",*t=")",
        m2 = R"(",*u=")",
        m3 = R"(",*v=")",
        en = R"(";void r(char *w){int p = -1;while(w[++p])if(w[p]<0)std::cout<<d[w[p]+128];else std::cout<<w[p];}int main(){r(s);r(t);r(u);r(v);return 0;})";

char *d[] = {"\n", "\"", "\\", " the ", " of ", " and ", " to ", " a ", " in ", " that ", " is ", " it ", " or "};

string compress(char *s, ssize_t sz) {
    s[sz] = 0;
    string res;
    int i;
    for (i = 0; i < sz - 5; i++) {
        if (s[i] == '\n')
            res += (char) (0 - 128);
        else if (s[i] == '"')
            res += (char) (1 - 128);
        else if (s[i] == '\\')
            res += (char) (2 - 128);
        else if (s[i] == ' ') {
            if (s[i + 1] == 't' && s[i + 2] == 'h' && s[i + 3] == 'e' && s[i + 4] == ' ') {
                res += (char) (3 - 128);
                i += 4;
            } else if (s[i + 1] == 'o' && s[i + 2] == 'f' && s[i + 3] == ' ') {
                res += (char) (4 - 128);
                i += 3;
            } else if (s[i + 1] == 'a' && s[i + 2] == 'n' && s[i + 3] == 'd' && s[i + 4] == ' ') {
                res += (char) (5 - 128);
                i += 4;
            } else if (s[i + 1] == 't' && s[i + 2] == 'o' && s[i + 3] == ' ') {
                res += (char) (6 - 128);
                i += 3;
            } else if (s[i + 1] == 'a' && s[i + 2] == ' ') {
                res += (char) (7 - 128);
                i += 2;
            } else if (s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == ' ') {
                res += (char) (8 - 128);
                i += 3;
            } else if (s[i + 1] == 't' && s[i + 2] == 'h' && s[i + 3] == 'a' && s[i + 4] == 't' && s[i + 5] == ' ') {
                res += (char) (9 - 128);
                i += 5;
            } else if (s[i + 1] == 'i' && s[i + 2] == 's' && s[i + 3] == ' ') {
                res += (char) (10 - 128);
                i += 3;
            } else if (s[i + 1] == 'i' && s[i + 2] == 't' && s[i + 3] == ' ') {
                res += (char) (11 - 128);
                i += 3;
            } else if (s[i + 1] == 'o' && s[i + 2] == 'r' && s[i + 3] == ' ') {
                res += (char) (12 - 128);
                i += 3;
            } else
                res += s[i];
        } else
            res += s[i];
    }
    for (; i < sz; i++) {
        if (s[i] == '\n')
            res += (char) (0 - 128);
        else if (s[i] == '"')
            res += (char) (1 - 128);
        else if (s[i] == '\\')
            res += (char) (2 - 128);
        else
            res += s[i];
    }
    return res;
}

int main() {
    char s[16385];
    ssize_t sz, res_sz = 0, total_sz = 0;
    cout << beg;
    res_sz += beg.length();
    while ((sz = read(0, s, 2048))) {
        total_sz += sz;
        string c = compress(s, sz);
        if (c != "") {
            cout << c << '"' << '\n' << '"';
            res_sz += c.length() + 3;
        }
        if (res_sz > 50000 && m1.length()) {
            cout << m1;
            m1 = "";
        }
        if (res_sz > 100000 && m2.length()) {
            cout << m2;
            m2 = "";
        }
        if (res_sz > 150000 && m3.length()) {
            cout << m3;
            m3 = "";
        }
    }
    cout << m1 << m2 << m3 << en;
    res_sz += en.length() + m1.length() + m2.length() + m3.length();
    if (res_sz >= total_sz) return 1;
    return 0;
}