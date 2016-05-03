#include <iostream>
#include <list>

using namespace std;

struct amdate {
    long long int amount;
    int date;
};

class Period {
    list <amdate> trans;
public:
    long long int end = 0;
    long long int dec = 0;

    void add(int date, long long int amount) {
        bool added = false;
        long long int balance = 0;
        long long int min_b = 0;
        for (auto it = trans.begin(); it != trans.end(); ++it) {
            if (it->date > date) {
                if (!added) {
                    added = true;
                    trans.insert(it, {amount, date});
                    balance += amount;
                    min_b = min(min_b, balance);
                }
                balance += it->amount;
            } else {
                balance += it->amount;
            }
            min_b = min(min_b, balance);
        }
        if (added) {
            end = balance;
            dec = min_b;
        } else {
            trans.push_back({amount, date});
            end += amount;
            dec = min(dec, end);
        }
    }
};

int str_to_date(string d, string t) {
    int dd, MM, hh, mm;
    dd = (d[0] - '0') * 10 + (d[1] - '0');
    MM = (d[3] - '0') * 10 + (d[4] - '0');
    hh = (t[0] - '0') * 10 + (t[1] - '0');
    mm = (t[3] - '0') * 10 + (t[4] - '0');
    return (mm - 1) + 60 * ((hh - 1) + 24 * ((dd - 1) + 31 * (MM - 1)));
}

int main() {
    const int buckets = 5400;
    Period period[buckets];
    Period period100[buckets/100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int amount, date;
        string d, t;
        cin >> amount >> d >> t;
        date = str_to_date(d, t);
        period[date / 100].add(date, amount);

        long long int min_dec = 0;
        long long int balance = 0;
        for (int j = 100*(date/10000); j < 100*(date/10000)+100; j++) {
            min_dec = min(min_dec, balance + period[j].dec);
            balance += period[j].end;
        }
        period100[date/10000].dec = min_dec;
        period100[date/10000].end = balance;

        min_dec = 0;
        balance = 0;
        for (int j = 0; j < buckets/100; j++) {
            min_dec = min(min_dec, balance + period100[j].dec);
            balance += period100[j].end;
        }
        cout << min_dec << endl;
    }
    return 0;
}