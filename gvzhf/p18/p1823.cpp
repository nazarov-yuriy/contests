#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {
    double nu = 8.314;
    map<string, int> inp;
    for (int i = 0; i < 3; i++) {
        string a, b;
        int v;
        cin >> a >> b >> v;
        inp[a] = v;
    }
    if (inp.count("p") && inp.count("n") && inp.count("V")) {
        if (inp["V"] == 0)
            cout << "error";
        else if (inp["n"] == 0 && inp["p"] == 0)
            cout << "undefined";
        else if (inp["n"] == 0 && inp["p"] != 0)
            cout << "error";
        else if (inp["p"] == 0)
            cout << "error";
        else
            cout << "T = " << setprecision(10) << ((double) inp["p"] * inp["V"]) / nu / inp["n"];
    } else if (inp.count("p") && inp.count("T") && inp.count("V")) {
        if (inp["V"] == 0 || inp["T"] == 0)
            cout << "error";
        else
            cout << "n = " << setprecision(10) << ((double) inp["p"] * inp["V"]) / nu / inp["T"];
    } else if (inp.count("p") && inp.count("n") && inp.count("T")) {
        if (inp["T"] == 0)
            cout << "error";
        else if (inp["p"] == 0 && inp["n"] == 0)
            cout << "undefined";
        else if (inp["p"] == 0 && inp["n"] != 0)
            cout << "error";
        else if (inp["n"] == 0)
            cout << "error";
        else
            cout << "V = " << setprecision(10) << ((double) inp["n"] * inp["T"] * nu) / inp["p"];
    } else if (inp.count("T") && inp.count("n") && inp.count("V")) {
        if (inp["V"] == 0 || inp["T"] == 0)
            cout << "error";
        else
            cout << "p = " << setprecision(10) << ((double) inp["n"] * inp["T"] * nu) / inp["V"];
    }
    return 0;
}