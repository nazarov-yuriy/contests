#include <iostream>

using namespace std;

struct fn {
    string digits;
    int sign;
    int exp;
};

fn parse(string str) {
    fn res = {};
    string val, exp;
    int state = 0;
    for (int i = 0; i < str.length(); i++) {
        if (0 == state) {
            if (str[i] == 'e' || str[i] == 'E') {
                state = 1;
            } else {
                val += str[i];
            }
        } else {
            if (str[i] == 'e' || str[i] == 'E') {
                return res;
            } else {
                exp += str[i];
            }
        }
    }
    {
        bool neg_exp = false;
        if ((exp == "-") || (exp == "+") || (exp == "" && state)) return res;
        for (int i = 0; i < exp.length(); i++) {
            if (res.exp < 100000000) res.exp *= 10;
            if (0 == i && (exp[i] == '-' || exp[i] == '+')) {
                neg_exp = exp[i] == '-';
            } else if (('0' <= exp[i]) && (exp[i] <= '9')) {
                res.exp += exp[i] - '0';
            } else {
                return res;
            }
        }
        if (neg_exp) res.exp *= -1;
    }
    string tmp;
    int sign = 0;
    if (val[0] == '-') {
        tmp = val.substr(1);
        sign = -1;
    } else if (val[0] == '+') {
        tmp = val.substr(1);
        sign = 1;
    } else {
        tmp = val;
        sign = 1;
    }
    if (tmp == "" || tmp == "." || tmp[tmp.length() - 1] == '.') return res;
    int pos = -1;
    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] == '.') {
            if (pos >= 0)
                return res;
            else
                pos = i;
        } else if (('0' <= tmp[i]) && (tmp[i] <= '9')) {
            res.digits += tmp[i];
        } else {
            return res;
        }
    }
    if (pos >= 0) res.exp -= (tmp.length() - pos - 1);
    res.sign = sign;
    return res;
}

void print_fn(fn res, int n) {
    if (res.sign == 0) {
        cout << "Not a floating point number" << endl;
    } else {
        bool zero = true;
        string str;
        for (int i = 0; i < (((int) (res.digits.length())) + min(0, res.exp)); i++) {
            if (!zero || res.digits[i] != '0') {
                str += res.digits[i];
                zero = false;
            }
        }
        if (zero) str = "0";
        else
            for (int i = 0; i < res.exp; i++) {
                str += '0';
            }
        if (n) {
            str += '.';
            for (int i = 0; i < n; i++) {
                int pos = i + (int) res.digits.length() + (int) res.exp;
                if (0 <= pos && pos < res.digits.length()) {
                    str += res.digits[pos];
                    zero &= res.digits[pos] == '0';
                } else {
                    str += '0';
                }
            }
        }
        if (res.sign < 0 && !zero) cout << '-';
        cout << str << endl;
    }
}

int main() {
    string str, tmp;
    int n;
    while (1) {
        getline(cin, str);
        if (str == "#") break;
        cin >> n;
        getline(cin, tmp);
        print_fn(parse(str), n);
    }
    return 0;
}